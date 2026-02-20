#pragma once

#include "Shield_manager.h"

#include <Arduino.h>


class Shoting_program
{
  public:
  Shoting_program(Shield_manager& _manager)
  : manager(_manager)
  {}
  virtual ~Shoting_program() {}

  void start()
  {
    resetTimer();
    running = true;
    onStart();
  }

  void stop()
  {
    running = false;
    onStop();
  }

  void update()
  {
    if (!running)
      return;
    updateTimer();
    onUpdate();
    drawUI();
  }

  protected:
  virtual void onStart() = 0;
  virtual void onStop() = 0;
  virtual void onUpdate() = 0;
  virtual void drawUI() = 0;

  void resetTimer()
  {
    startTime = millis();
  }
  void updateTimer()
  {
    elapsed = millis() - startTime;
  }

  Shield_manager& manager;
  bool running = false;
  unsigned long startTime = 0;
  unsigned long elapsed = 0;
};
