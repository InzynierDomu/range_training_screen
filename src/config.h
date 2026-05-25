#pragma once

#include <stddef.h>
#include <stdint.h>

// ─── Log levels — muszą być #define (używane w #if w logger.h) ───────────────
// LOG_LEVEL_NONE  0  — brak logów
// LOG_LEVEL_ERROR 1  — tylko błędy krytyczne
// LOG_LEVEL_WARN  2  — ostrzeżenia + błędy
// LOG_LEVEL_INFO  3  — wszystkie komunikaty
#define LOG_LEVEL_NONE  0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_INFO  3

#define LOG_LEVEL    LOG_LEVEL_INFO
#define LOG_SD_LEVEL LOG_LEVEL_WARN  // co trafia na kartę SD (NONE = wyłączone)

// ─── WiFi / AP ────────────────────────────────────────────────────────────────
constexpr const char* AP_SSID = "Strzelinca";
constexpr const char* AP_PASS = "inzynierDomu";

// ─── ESP-NOW ──────────────────────────────────────────────────────────────────
// Statyczny MAC legacy (single-peer fallback); docelowe tarcze ładowane z SD
constexpr uint8_t PEER_MAC_LEGACY[] = { 0x3C, 0xE9, 0x0E, 0x7F, 0x30, 0x58 };
constexpr uint8_t ESPNOW_CHANNEL = 1;

// ─── SD / config ──────────────────────────────────────────────────────────────
constexpr const char* SHIELDS_CONFIG_FILE = "/config.json";
constexpr size_t SHIELDS_CONFIG_JSON_SIZE = 2048;
constexpr const char* LOG_SD_FILE = "/log.txt";

// ─── Havy Fire ────────────────────────────────────────────────────────────────
constexpr unsigned long HV_DURATION_MS = 10000UL;
