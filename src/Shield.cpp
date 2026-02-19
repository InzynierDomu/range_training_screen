#include "Shield.h"

#include "Frame.h"

#include <esp_now.h>

Shield::Shield(uint8_t id, const uint8_t mac[6])
: id(id)
, state(Shield_state::none)
{
  memcpy(peerAddress, mac, 6);
}

uint8_t Shield::get_id() const
{
  return id;
}

Shield_state Shield::get_state() const
{
  return state;
}

void Shield::set_state(Shield_state state)
{
  uint8_t msg = static_cast<uint8_t>(state);
  send_esp_now(msg);
}

void Shield::set_hit_callback(HitCallback callback)
{
  onHit = callback;
}

void Shield::send_esp_now(uint8_t value)
{
  message_t sendMsg;
  sendMsg.id = 1; // todo move id master board
  sendMsg.value = value;
  Serial.println("Sending via esp now");

  esp_err_t result = esp_now_send(peerAddress, (uint8_t*)&sendMsg, sizeof(sendMsg));
  if (result != ESP_OK)
  {
    Serial.println(result);
    Serial.println("Sending error");
  }
}