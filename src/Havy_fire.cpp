#include "Havy_fire.h"

#include "ui.h"

void Havy_fire::onOpen()
{
  Serial.println("hv open");
  manager.set_all_inactive();
}
void Havy_fire::onStart()
{
  Serial.println("hv start");
  hits = 0;
  id_actve_shield = manager.get_full_random_id();
  manager.send_message(Shield_state::ready, id_actve_shield);
}

void Havy_fire::onStop()
{
  Serial.println("hv stop");
  manager.set_all_inactive();
}

void Havy_fire::onClose()
{
  Serial.println("hv Close");
}

void Havy_fire::onUpdate()
{
  if (elapsed >= 10000)
  {
    elapsed = 10000;
    stop();
  }
}

void Havy_fire::drawUI()
{
  char buffer[10]; // Tablica na tekst, np. "12.34\0"
  unsigned long seconds = elapsed / 1000;
  unsigned long hundredths = (elapsed % 1000) / 10; // Pobieramy dwie pierwsze cyfry milisekund

  sprintf(buffer, "%lu.%02lu", seconds, hundredths);
  lv_textarea_set_text(ui_hvtimer, buffer);
  snprintf(buffer, sizeof(buffer), "%u", hits);
  lv_textarea_set_text(ui_hvresult, buffer);
}

void Havy_fire::onShieldHit(uint8_t shieldId)
{
  Serial.println("on hit");
  hits++;
  id_actve_shield = manager.get_random_id(shieldId);
  manager.send_message(Shield_state::ready, id_actve_shield);
}