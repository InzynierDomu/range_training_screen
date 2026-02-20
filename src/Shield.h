#pragma once

#include <functional>

enum Shield_state
{
  not_active = 0,
  none,
  ready,
  shoted,
  hostage,
  waiting,
};

class Shield
{
  public:
  using HitCallback = std::function<void(uint8_t id)>;

  Shield(uint8_t id, const uint8_t mac[6]);

  uint8_t get_id() const;
  Shield_state get_state() const;
  void set_state(Shield_state state);
  void set_hit_callback(HitCallback callback);
  void handle_message(const uint8_t* data, int len);

  private:
  void send_esp_now(uint8_t value);

  uint8_t id;
  uint8_t peerAddress[6];
  Shield_state state;
  HitCallback onHit = nullptr;
};