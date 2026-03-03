#include "Shield_manager.h"

void Shield_manager::setGlobalHitCallback(HitCallback cb)
{
  globalHitCallback = cb;
}

void Shield_manager::handle_message(const message_t& msg, const uint8_t* mac)
{
  Serial.println("msg handle");
  Shield* s = findById(macToId(mac));
  if (s)
  {
    uint8_t stateByte = msg.value;
    s->handle_message(&stateByte, 1); // aktualizuje stan wewnętrzny

    // Proxy: przekaż dalej do aktywnego programu
    if (globalHitCallback)
    {
      globalHitCallback(macToId(mac));
    }
  }
}

void Shield_manager::addShield(Shield* shield)
{
  shields.push_back(shield);
}

void Shield_manager::send_message(Shield_state state, uint8_t shield_id)
{
  auto shield = findById(shield_id);
  shield->set_state(state);
}

int Shield_manager::getShieldCount() const
{
  return shields.size();
}

uint8_t Shield_manager::get_full_random_id()
{
  uint8_t number = random(getShieldCount() - 1);
  return shields[number]->get_id();
}

uint8_t Shield_manager::get_random_id(uint8_t last_id)
{
  if (getShieldCount() > 1)
  {
    uint8_t number;
    do
    {
      number = get_full_random_id();
    } while (number != last_id);
    return shields[number]->get_id();
  }
  else
  {
    return get_full_random_id();
  }
}

void Shield_manager::set_all_inactive()
{
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
  // XOR ostatnich 3 oktetów – unikalność wystarczająca dla małej sieci
  return mac[3] ^ mac[4] ^ mac[5];
}