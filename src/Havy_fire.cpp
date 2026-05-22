#include "Havy_fire.h"
#include "config.h"
#include "logger.h"
#include "ui.h"

static const char* TAG = "HavyFire";

void Havy_fire::onOpen()
{
  LOG_I(TAG, "onOpen");
  manager.set_all_inactive();
}

void Havy_fire::onStart()
{
  LOG_I(TAG, "onStart — tarcz dostępnych: %d", manager.getShieldCount());
  if (manager.getShieldCount() == 0)
  {
    LOG_E(TAG, "onStart: brak tarcz — program nie może startować");
    return;
  }
  hits = 0;
  id_actve_shield = manager.get_full_random_id();
  LOG_I(TAG, "pierwsza aktywna tarcza id=%d", id_actve_shield);
  manager.send_message(Shield_state::ready, id_actve_shield);
}

void Havy_fire::onStop()
{
  LOG_I(TAG, "onStop — trafień: %d", hits);
  manager.set_all_inactive();
}

void Havy_fire::onClose()
{
  LOG_I(TAG, "onClose");
}

void Havy_fire::onUpdate()
{
  if (elapsed >= HV_DURATION_MS)
  {
    elapsed = HV_DURATION_MS;
    stop();
  }
}

void Havy_fire::drawUI()
{
  char buffer[10];
  unsigned long seconds = elapsed / 1000;
  unsigned long hundredths = (elapsed % 1000) / 10;

  sprintf(buffer, "%lu.%02lu", seconds, hundredths);
  lv_textarea_set_text(ui_hvtimer, buffer);
  snprintf(buffer, sizeof(buffer), "%u", hits);
  lv_textarea_set_text(ui_hvresult, buffer);
}

void Havy_fire::onShieldHit(uint8_t shieldId)
{
  hits++;
  LOG_I(TAG, "trafienie w tarczę id=%d, łącznie trafień: %d", shieldId, hits);
  id_actve_shield = manager.get_random_id(shieldId);
  LOG_I(TAG, "następna tarcza id=%d", id_actve_shield);
  manager.send_message(Shield_state::ready, id_actve_shield);
}
