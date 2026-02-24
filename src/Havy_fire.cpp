#include "Havy_fire.h"

#include "ui.h"


void Havy_fire::onOpen()
{
  Serial.println("hv open");
}
void Havy_fire::onStart()
{
  Serial.println("hv start");
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
  Serial.println("hv update");
}

void Havy_fire::drawUI()
{
  Serial.println("hv draw ui");
  char buffer[10]; // Tablica na tekst, np. "12.34\0"
  unsigned long seconds = elapsed / 1000;
  unsigned long hundredths = (elapsed % 1000) / 10; // Pobieramy dwie pierwsze cyfry milisekund

  sprintf(buffer, "%lu.%02lu", seconds, hundredths);
//   snprintf(buf, sizeof(buf), "%d.%02d", sec, cs);
  lv_textarea_set_text(ui_hvtimer, buffer);
}