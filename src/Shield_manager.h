#pragma once

#include "Frame.h"
#include "Shield.h"

#include <functional>
#include <vector>


class Shield_manager
{
  public:
  using HitCallback = std::function<void(uint8_t shieldId)>;

  void setGlobalHitCallback(HitCallback cb);
  void handle_message(const message_t& msg, const uint8_t* mac);
  void addShield(Shield* shield);
  void send_message(Shield_state state, uint8_t shield_id);
  int getShieldCount() const;
  uint8_t get_full_random_id();
  uint8_t get_random_id(uint8_t last_id);
  void set_all_inactive();
  uint8_t macToId(const uint8_t* mac);

  private:
  Shield* findById(uint8_t id);

  HitCallback globalHitCallback = nullptr;
  std::vector<Shield*> shields;
};