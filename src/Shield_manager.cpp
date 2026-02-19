#include "Shield_manager.h"

void Shield_manager::setGlobalHitCallback(HitCallback cb)
{
  globalHitCallback = cb;
}

void Shield_manager::handle_message(const uint8_t* mac, const message_t& msg)
{
  Shield* s = findById(msg.id);
  if (s)
  {
    uint8_t stateByte = msg.value;
    s->handle_message(&stateByte, 1); // aktualizuje stan wewnętrzny

    // Proxy: przekaż dalej do aktywnego programu
    if (msg.value == shoted && globalHitCallback)
    {
      globalHitCallback(msg.id);
    }
  }
}

void Shield_manager::addShield(Shield* shield)
{
  shields.push_back(shield);
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