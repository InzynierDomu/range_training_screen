#include "Shield_manager.h"
#include "logger.h"

static const char* TAG = "ShieldMgr";

void Shield_manager::setGlobalHitCallback(HitCallback cb)
{
  globalHitCallback = cb;
}

void Shield_manager::handle_message(const message_t& msg, const uint8_t* mac)
{
  uint8_t id = macToId(mac);
  Shield* s = findById(id);
  if (!s)
  {
    LOG_W(TAG, "handle_message: nieznany MAC %02X:%02X:%02X:%02X:%02X:%02X (id=%d)",
          mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], id);
    return;
  }

  LOG_I(TAG, "odebrano wiadomość od tarczy id=%d, value=%d", id, msg.value);
  uint8_t stateByte = msg.value;
  s->handle_message(&stateByte, 1);

  if (globalHitCallback)
  {
    globalHitCallback(id);
  }
}

void Shield_manager::addShield(Shield* shield)
{
  shields.push_back(shield);
  LOG_I(TAG, "dodano tarczę id=%d", shield->get_id());
}

void Shield_manager::send_message(Shield_state state, uint8_t shield_id)
{
  Shield* shield = findById(shield_id);
  if (!shield)
  {
    LOG_E(TAG, "send_message: tarcza id=%d nie istnieje", shield_id);
    return;
  }
  LOG_I(TAG, "send_message: tarcza id=%d, stan=%d", shield_id, static_cast<int>(state));
  shield->set_state(state);
}

int Shield_manager::getShieldCount() const
{
  return shields.size();
}

uint8_t Shield_manager::get_full_random_id()
{
  if (shields.empty())
  {
    LOG_E(TAG, "get_full_random_id: brak tarcz na liście!");
    return 0;
  }
  uint8_t index = random(getShieldCount()); // fix: było random(count-1) — off-by-one
  return shields[index]->get_id();
}

uint8_t Shield_manager::get_random_id(uint8_t last_id)
{
  if (getShieldCount() > 1)
  {
    uint8_t id;
    do
    {
      id = get_full_random_id();
    } while (id == last_id); // fix: było != — warunek odwrócony; fix: zwracamy id, nie shields[id]
    return id;
  }
  return get_full_random_id();
}

void Shield_manager::set_all_inactive()
{
  LOG_I(TAG, "set_all_inactive: %d tarcz", getShieldCount());
  for (auto* s : shields)
  {
    s->set_state(Shield_state::not_active);
  }
}

Shield* Shield_manager::findById(uint8_t id)
{
  for (auto* s : shields)
  {
    if (s->get_id() == id)
      return s;
  }
  return nullptr;
}

uint8_t Shield_manager::macToId(const uint8_t* mac)
{
  return mac[3] ^ mac[4] ^ mac[5];
}
