#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

#define LED_PIN 10 // WS2812 na ESP32-C3-Zero
#define LED_COUNT 1 // tylko 1 dioda na płytce

#define RX1_PIN 3 // odbiór z konwertera USB-UART
#define TX1_PIN 2 // wysyłanie do konwertera USB-UART

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

const uint32_t m_on_led_time = 1000;
volatile bool led_status = false;
volatile long timer = 0;
volatile bool msg_recived;

// Struktura wiadomości (ta sama co w masterze)
typedef struct
{
  int id;
  float value;
  char msg[32];
} message_t;

message_t myData;

uint8_t masterMac[] = {0x20, 0x6E, 0xF1, 0x87, 0xBA, 0x9C}; // MAC mastera

void send_msg()
{
  myData.id = 2; // ID slave
  myData.value = 23.5;
  strcpy(myData.msg, "Slave OK");

  if (!esp_now_is_peer_exist(masterMac))
  {
    Serial.println("add peer");
    esp_now_peer_info_t peerInfo;
    memcpy(peerInfo.peer_addr, masterMac, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;
    if (esp_now_add_peer(&peerInfo) != ESP_OK)
    {
      Serial.println("Failed to add peer");
      return;
    }
  }
  else
  {
    Serial.println("master peer exist");
  }

  esp_err_t result = esp_now_send(masterMac, (uint8_t*)&myData, sizeof(myData));
  if (result == ESP_OK)
  {
    Serial.println("Wysłano do mastera: OK");
  }
  else
  {
    Serial.println(result);
    Serial.println("Błąd wysyłania");
  }
}

void OnDataRecv(const uint8_t* mac, const uint8_t* incomingData, int len)
{
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Odebrano od: ");
  Serial.print(mac[0], HEX);
  Serial.print(":");
  Serial.print(mac[1], HEX);
  Serial.print(":");
  Serial.print(mac[2], HEX);
  Serial.print(":");
  Serial.print(mac[3], HEX);
  Serial.print(":");
  Serial.print(mac[4], HEX);
  Serial.print(":");
  Serial.println(mac[5], HEX);
  Serial.printf("ID: %d, Value: %.2f, Msg: %s\n", myData.id, myData.value, myData.msg);

  led_status = true;
  timer = millis();
  strip.setPixelColor(0, strip.Color(0, 0, 255));
  Serial.println("led_high");
  msg_recived = true;
}

void setup()
{
  strip.begin(); // inicjalizacja NeoPixel

  strip.setPixelColor(0, strip.Color(255, 0, 0));
  strip.show();

  Serial1.begin(115200);
  Serial.println("setup start");

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK)
  {
    Serial.println("Błąd inicjalizacji ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  delay(1000);

  Serial.println("ESP32-C3-Zero SLAVE gotowy. Kanał WiFi: " + String(WiFi.channel()));
  Serial.print("MAC Slave: ");
  Serial.println(WiFi.macAddress());

  Serial.println("led_low");
  Serial.println("setup end");

  strip.setPixelColor(0, strip.Color(0, 255, 0));
  strip.show();
}
void loop()
{
  if (led_status)
  {
    if (millis() - timer > m_on_led_time)
    {
      led_status = false;
      strip.setPixelColor(0, strip.Color(0, 255, 0));
      Serial.println("led_low");
    }
  }

  if (msg_recived)
  {
    send_msg();
    msg_recived = false;
  }
}