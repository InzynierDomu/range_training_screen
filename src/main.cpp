#include "Frame.h"
#include "Havy_fire.h"
#include "Program.h"
#include "Shield.h"
#include "Shield_manager.h"
#include "actions.h"
#include "config.h"
#include "logger.h"
#include "ui.h"

#include "LGFX.h"

#include <Arduino.h>
#include <ArduinoJson.h>
#include <SD.h>
#include <SPI.h>
#include <WebServer.h>
#include <WiFi.h>
#include <esp_now.h>
#include <lvgl.h>
#include <memory>
#include <vector>

static const char* TAG = "Main";


const char* apSsid = AP_SSID;
const char* apPass = AP_PASS;

Shield_manager shield_manager;
std::unique_ptr<Shoting_program> activeProgram;
// globalny lub dostępny w main
bool loadShieldsConfig(const char* filename)
{
  if (!SD.begin())
  {
    LOG_E(TAG, "brak karty SD");
  }
  else
  {
    LOG_I(TAG, "karta SD OK");
  }

  File file = SD.open(filename);
  if (!file)
  {
    LOG_E(TAG, "nie można otworzyć pliku konfiguracji: %s", filename);
    return false;
  }

  StaticJsonDocument<SHIELDS_CONFIG_JSON_SIZE> doc;
  DeserializationError error = deserializeJson(doc, file);
  file.close();

  if (error)
  {
    LOG_E(TAG, "błąd parsowania JSON: %s", error.c_str());
    return false;
  }

  JsonArray arr = doc["shields"].as<JsonArray>();
  if (arr.isNull())
  {
    LOG_W(TAG, "nie znaleziono tablicy 'shields' w pliku");
    return false;
  }

  for (JsonObject obj : arr)
  {
    uint8_t mac[6];
    JsonArray macArr = obj["mac"].as<JsonArray>();
    if (!macArr || macArr.size() != 6)
      continue;

    for (uint8_t i = 0; i < 6; ++i)
    {
      mac[i] = macArr[i].as<uint8_t>();
    }

    uint8_t id = shield_manager.macToId(mac);

    auto* shield = new Shield(id, mac);
    shield_manager.addShield(shield);

    LOG_I(TAG, "załadowano tarczę id=%d, MAC=%02X:%02X:%02X:%02X:%02X:%02X",
          id, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  }

  return true;
}

void switchProgram(std::unique_ptr<Shoting_program> program)
{
  if (activeProgram)
  {
    activeProgram->close();
  }
  activeProgram = std::move(program);
  if (activeProgram)
  {
    activeProgram->open();
  }
}

// Struktura wiadomości - musi być identyczna na obu urządzeniach
// typedef struct
// {
//   int id;
//   uint8_t value;
// } message_t;

message_t receivedMsg; // Przechowuje odebraną wiadomość
// message_t sendMsg; // Wiadomość do wysłania
WebServer server(80);


LGFX lcd;

#define TFT_BL 2
SPIClass& spi = SPI;
#include "touch.h"

static uint32_t screenWidth;
static uint32_t screenHeight;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t disp_draw_buf[800 * 480 / 15];
static lv_disp_drv_t disp_drv;
void my_disp_flush(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p)
{

  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
  lcd.pushImageDMA(area->x1, area->y1, w, h, (lgfx::rgb565_t*)&color_p->full);
#else
  lcd.pushImageDMA(area->x1, area->y1, w, h,
                   (lgfx::rgb565_t*)&color_p->full); //
#endif

  lv_disp_flush_ready(disp);
}
void my_touchpad_read(lv_indev_drv_t* indev_driver, lv_indev_data_t* data)
{
  if (touch_has_signal())
  {
    if (touch_touched())
    {
      data->state = LV_INDEV_STATE_PR;

      data->point.x = touch_last_x;
      data->point.y = touch_last_y;
      Serial.print("Data x ");
      Serial.println(data->point.x);
      Serial.print("Data y ");
      Serial.println(data->point.y);
    }
    else if (touch_released())
    {
      data->state = LV_INDEV_STATE_REL;
    }
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
  delay(15);
}

// wysyłanie wiadomości
// void sendMessage()
// {
//   sendMsg.id = 1; // id dla porządku
//   sendMsg.value = 1; // dummy value
//   Serial.println("Sending via esp now");

//   esp_err_t result = esp_now_send(peerAddress, (uint8_t*)&sendMsg, sizeof(sendMsg));
//   if (result != ESP_OK)
//   {
//     Serial.println(result);
//     Serial.println("Sending error");
//   }
// }
void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status)
{
  if (status == ESP_NOW_SEND_SUCCESS)
    LOG_I(TAG, "ESP-NOW send OK");
  else
    LOG_W(TAG, "ESP-NOW send FAIL");
}

// ta funkcja jest wywoływana jak przychodzi wiadomość po esp now, np. od slave można wykorzsytać do czegoś np. myData.value, myData.msg
void OnDataRecv(const uint8_t* mac, const uint8_t* data, int len)
{
  memcpy(&receivedMsg, data, sizeof(receivedMsg));
  LOG_I(TAG, "ESP-NOW recv od %02X:%02X:%02X:%02X:%02X:%02X, value=%d",
        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], receivedMsg.value);
  shield_manager.handle_message(receivedMsg, mac);
}

static unsigned long hv_start_ms = 0;
void hv_open()
{
  // program = Program::havy_fire;
  // hv_start_ms = millis();
  // lv_textarea_set_text(ui_hvtimer, "0.00");
  // lv_textarea_set_text(ui_hvresult, "0");
  // sendMessage();
  switchProgram(std::make_unique<Havy_fire>(shield_manager));
}

void hv_start()
{
  activeProgram->start();
}

void hv_stop()
{
  activeProgram->stop();
}

void hv_close()
{
  // program = Program::none;
}

void handleRoot()
{
  server.send(200,
              "text/html",
              "<html><body><h1>HV Timer</h1>"
              "<p>Device is running.</p>"
              "</body></html>");
}
void setup()
{
  Serial.begin(115200);

  lcd.begin();
  lv_init();
  touch_init();

  screenWidth = lcd.width();
  screenHeight = lcd.height();

  lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth * screenHeight / 15);

  lv_disp_drv_init(&disp_drv);

  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  ledcSetup(1, 300, 8);
  ledcAttachPin(TFT_BL, 1);
  ledcWrite(1, 255);

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, LOW);
  delay(500);
  digitalWrite(TFT_BL, HIGH);

  ui_init();

  lv_timer_handler();

  WiFi.mode(WIFI_STA); // AP + (opcjonalnie STA)

  // WiFi.softAP(apSsid, apPass); // TODO: check

  if (esp_now_init() != ESP_OK)
  {
    LOG_E(TAG, "błąd inicjalizacji ESP-NOW");
    return;
  }
  LOG_I(TAG, "ESP-NOW zainicjalizowany");

  server.on("/", handleRoot);
  server.begin();
  LOG_I(TAG, "HTTP server uruchomiony");
  LOG_I(TAG, "MAC: %s, IP: %s, kanał: %d",
        WiFi.macAddress().c_str(),
        WiFi.localIP().toString().c_str(),
        WiFi.channel());

  esp_now_register_send_cb(OnDataSent);

  if (loadShieldsConfig(SHIELDS_CONFIG_FILE))
  {
    LOG_I(TAG, "załadowano tarcze (%d szt.)", shield_manager.getShieldCount());
    shield_manager.add_peers();
  }
  else
    LOG_W(TAG, "nie załadowano tarcz — start programu będzie niemożliwy");

  esp_now_register_recv_cb(OnDataRecv);

  // program = Program::none;
}

void loop()
{
  lv_timer_handler();
  delay(5);

  // if (program == Program::havy_fire)
  // {
  //   unsigned long now = millis();
  //   float elapsed = (now - hv_start_ms) / 1000.0f; // ile sekund minęło

  //   if (elapsed >= 10.0f)
  //   {
  //     elapsed = 10.0f;
  //     program = Program::none;
  //   }

  //   // zaokrąglenie do 2 miejsc, żeby np. 1.999 → 2.00
  //   int centis = (int)(elapsed * 100 + 0.5f);
  //   int sec = centis / 100;
  //   int cs = centis % 100;

  //   char buf[16];
  //   snprintf(buf, sizeof(buf), "%d.%02d", sec, cs);
  //   lv_textarea_set_text(ui_hvtimer, buf);
  // }
  if (activeProgram)
  {
    if (activeProgram->is_running())
    {
      activeProgram->update();
    }
  }

  server.handleClient();
}
