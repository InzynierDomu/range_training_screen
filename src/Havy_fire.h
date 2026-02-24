#pragma once

#include "Program.h"

class Havy_fire : public Shoting_program
{
  using Shoting_program::Shoting_program;

  protected:
  void onOpen() override;
  void onStart() override;
  void onStop() override;
  void onClose() override;
  void onUpdate() override;
  void drawUI() override;
  void onShieldHit(uint8_t shieldId) override;

  // void update_timer();
  uint16_t hits;

};