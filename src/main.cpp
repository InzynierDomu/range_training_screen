#include "Frame.h"
#include "Shield.h"
#include "actions.h"
#include "ui.h"

#include <Arduino.h>
#include <ArduinoJson.h>
#include <LovyanGFX.hpp>
#include <SD.h>
#include <SPI.h>
#include <WebServer.h>
#include <WiFi.h>
#include <esp_now.h>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>
#include <lvgl.h>
#include <vector>


const char* apSsid = "Strzelinca";
const char* apPass = "inzynierDomu";

enum class Program
{
  havy_fire,
  dynamic,
  cover_fiire,
  training,
  hostage,
  none
};

Program program;

class LGFX : public lgfx::LGFX_Device
{
  public:
  lgfx::Bus_RGB _bus_instance;
  lgfx::Panel_RGB _panel_instance;
  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config();
      cfg.panel = &_panel_instance;

      cfg.pin_d0 = GPIO_NUM_15; // B0
      cfg.pin_d1 = GPIO_NUM_7; // B1
      cfg.pin_d2 = GPIO_NUM_6; // B2
      cfg.pin_d3 = GPIO_NUM_5; // B3
      cfg.pin_d4 = GPIO_NUM_4; // B4

      cfg.pin_d5 = GPIO_NUM_9; // G0
      cfg.pin_d6 = GPIO_NUM_46; // G1
      cfg.pin_d7 = GPIO_NUM_3; // G2
      cfg.pin_d8 = GPIO_NUM_8; // G3
      cfg.pin_d9 = GPIO_NUM_16; // GS4
      cfg.pin_d10 = GPIO_NUM_1; // G5

      cfg.pin_d11 = GPIO_NUM_14; // R0
      cfg.pin_d12 = GPIO_NUM_21; // R1
      cfg.pin_d13 = GPIO_NUM_47; // R2
      cfg.pin_d14 = GPIO_NUM_48; // R3
      cfg.pin_d15 = GPIO_NUM_45; // R4

      cfg.pin_henable = GPIO_NUM_41;
      cfg.pin_vsync = GPIO_NUM_40;
      cfg.pin_hsync = GPIO_NUM_39;
      cfg.pin_pclk = GPIO_NUM_0;
      cfg.freq_write = 15000000;

      cfg.hsync_polarity = 0;
      cfg.hsync_front_porch = 40;
      cfg.hsync_pulse_width = 48;
      cfg.hsync_back_porch = 40;

      cfg.vsync_polarity = 0;
      cfg.vsync_front_porch = 1;
      cfg.vsync_pulse_width = 31;
      cfg.vsync_back_porch = 13;

      cfg.pclk_active_neg = 1;
      cfg.de_idle_high = 0;
      cfg.pclk_idle_high = 0;

      _bus_instance.config(cfg);
    }
    {
      auto cfg = _panel_instance.config();
      cfg.memory_width = 800;
      cfg.memory_height = 480;
      cfg.panel_width = 800;
      cfg.panel_height = 480;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      _panel_instance.config(cfg);
    }
    _panel_instance.setBus(&_bus_instance);
    setPanel(&_panel_instance);
  }
};


std::vector<Shield*> shields; // globalny lub dostępny w main
bool loadShieldsConfig(const char* filename)
{
  if (!SD.begin())
  {
    Serial.println("no SD card");
  }
  else
  {
    Serial.println("SD card ok");
  }

  File file = SD.open(filename);
  if (!file)
  {
    Serial.println("❌ Nie można otworzyć pliku konfiguracji.");
    return false;
  }

  // Szacowane 1–2kB wystarczy przy kilku tarczach
  StaticJsonDocument<2048> doc;
  DeserializationError error = deserializeJson(doc, file);
  file.close();

  if (error)
  {
    Serial.printf("❌ Błąd parsowania JSON: %s\n", error.c_str());
    return false;
  }

  JsonArray arr = doc["shields"].as<JsonArray>();
  if (arr.isNull())
  {
    Serial.println("⚠️ Nie znaleziono tablicy 'shields' w pliku.");
    return false;
  }

  for (JsonObject obj : arr)
  {
    uint8_t id = obj["id"] | 0;

    uint8_t mac[6];
    JsonArray macArr = obj["mac"].as<JsonArray>();
    if (!macArr || macArr.size() != 6)
      continue;

    for (uint8_t i = 0; i < 6; ++i)
    {
      mac[i] = macArr[i].as<uint8_t>();
    }

    auto* shield = new Shield(id, mac);
    shields.push_back(shield);

    Serial.printf("✅ Załadowano tarczę ID=%d, MAC=%02X:%02X:%02X:%02X:%02X:%02X\n", id, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  }

  return true;
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

uint8_t peerAddress[] = {
    0x3C, 0xE9, 0x0E, 0x7F, 0x30, 0x58}; // MAC urządzenia do którego będzie wysyłana wiadomość, trzeba odczytać tam i wpisać tutaj

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
  Serial.print("Sending: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "ok" : "error");
}

// ta funkcja jest wywoływana jak przychodzi wiadomość po esp now, np. od slave można wykorzsytać do czegoś np. myData.value, myData.msg
void OnDataRecv(const uint8_t* mac, const uint8_t* data, int len)
{
  memcpy(&receivedMsg, data, sizeof(receivedMsg));
  Serial.printf("received from: %02X:%02X:%02X:%02X:%02X:%02X: ID=%d, Value=%d",
                mac[0],
                mac[1],
                mac[2],
                mac[3],
                mac[4],
                mac[5],
                receivedMsg.id,
                receivedMsg.value);

  // lv_label_set_text(ui_Label, receivedMsg.text);
}

static unsigned long hv_start_ms = 0;
void hv_start(void)
{
  program = Program::havy_fire;
  hv_start_ms = millis();
  lv_textarea_set_text(ui_hvtimer, "0.00");
  lv_textarea_set_text(ui_hvresult, "0");
  // sendMessage();
}

void hv_stop(void)
{
  program = Program::none;
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

  WiFi.mode(WIFI_AP_STA); // AP + (opcjonalnie STA)

  WiFi.softAP(apSsid, apPass); // TODO: check

  if (esp_now_init() != ESP_OK)
  {
    Serial.println("Blad inicjalizacji ESP-NOW");
    return;
  }

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");

  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.channel());

  esp_now_register_send_cb(OnDataSent);

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, peerAddress, 6);
  peerInfo.channel = 0; // ten sam kanał na obu ESP, 0 = aktualny
  peerInfo.encrypt = false;

  esp_err_t addStatus = esp_now_add_peer(&peerInfo);
  Serial.print("add_peer status: ");
  Serial.println(addStatus);


  if (addStatus != ESP_OK)
  {
    Serial.println("adding peer error");
  }

  if (loadShieldsConfig("/config.json"))
  {
    Serial.printf("Załadowano %d tarcz z pliku.\n", shields.size());
  }

  esp_now_register_recv_cb(OnDataRecv);

  program = Program::none;
}

void loop()
{
  lv_timer_handler();
  delay(5);

  if (program == Program::havy_fire)
  {
    unsigned long now = millis();
    float elapsed = (now - hv_start_ms) / 1000.0f; // ile sekund minęło

    if (elapsed >= 10.0f)
    {
      elapsed = 10.0f;
      program = Program::none;
    }

    // zaokrąglenie do 2 miejsc, żeby np. 1.999 → 2.00
    int centis = (int)(elapsed * 100 + 0.5f);
    int sec = centis / 100;
    int cs = centis % 100;

    char buf[16];
    snprintf(buf, sizeof(buf), "%d.%02d", sec, cs);
    lv_textarea_set_text(ui_hvtimer, buf);
  }

  server.handleClient();
}
