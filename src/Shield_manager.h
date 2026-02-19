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
  void handle_message(const uint8_t* mac, const message_t& msg);
  void addShield(Shield* shield);
  int getShieldCount() const;

  private:
  Shield* findById(uint8_t id);

  HitCallback globalHitCallback = nullptr;
  std::vector<Shield*> shields;
};