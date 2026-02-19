#pragma once

#include "Program.h"

class Havy_fire : public Shoting_program
{
  protected:
  void onStart() override;
  void onStop() override;
  void onUpdate() override;
  void drawUI() override;
};