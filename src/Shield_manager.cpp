#include "Shield_manager.h"

void Shield_manager::setGlobalHitCallback(HitCallback cb)
{
  globalHitCallback = cb;
}

void Shield_manager::handle_message(const message_t& msg)
{
  Serial.println("msg handle");
  Shield* s = findById(msg.id);
  if (s)
  {
    uint8_t stateByte = msg.value;
    s->handle_message(&stateByte, 1); // aktualizuje stan wewnętrzny

    // Proxy: przekaż dalej do aktywnego programu
    if (globalHitCallback)
    {
      globalHitCallback(msg.id);
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
Shield* Shield_manager::findById(uint8_t id)
{
  for (auto* s : shields)
  {
    if (s->get_id() == id)
      return s;
  }
  return nullptr;
}