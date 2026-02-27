#include "Havy_fire.h"

#include "ui.h"


void Havy_fire::onOpen()
{
  Serial.println("hv open");
}
void Havy_fire::onStart()
{
  Serial.println("hv start");
  manager.send_message(Shield_state::ready, 2);
  hits = 0;
}

void Havy_fire::onStop()
{
  Serial.println("hv stop");
}

void Havy_fire::onClose()
{
  Serial.println("hv Close");
}

void Havy_fire::onUpdate()
{
}

void Havy_fire::drawUI()
{
  char buffer[10]; // Tablica na tekst, np. "12.34\0"
  unsigned long seconds = elapsed / 1000;
  unsigned long hundredths = (elapsed % 1000) / 10; // Pobieramy dwie pierwsze cyfry milisekund

  sprintf(buffer, "%lu.%02lu", seconds, hundredths);
  //   snprintf(buf, sizeof(buf), "%d.%02d", sec, cs);
  lv_textarea_set_text(ui_hvtimer, buffer);
  // char buffer[2];
  snprintf(buffer, sizeof(buffer), "%u", hits);
  lv_textarea_set_text(ui_hvresult, buffer);
}

void Havy_fire::onShieldHit(uint8_t shieldId)
{
  Serial.println("on hit");
  hits++;
}