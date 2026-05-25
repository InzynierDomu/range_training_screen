#pragma once

#include "config.h"

#include <Arduino.h>

#if LOG_SD_LEVEL > LOG_LEVEL_NONE
void logger_sd_write(const char* entry);
#endif

// ── Serial dispatch ────────────────────────────────────────────────────────
#if LOG_LEVEL >= LOG_LEVEL_INFO
#define _LOG_SER_I(b) Serial.println(b)
#else
#define _LOG_SER_I(b)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#define _LOG_SER_W(b) Serial.println(b)
#else
#define _LOG_SER_W(b)
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR
#define _LOG_SER_E(b) Serial.println(b)
#else
#define _LOG_SER_E(b)
#endif

// ── SD dispatch ────────────────────────────────────────────────────────────
#if LOG_SD_LEVEL >= LOG_LEVEL_INFO
#define _LOG_SD_I(b) logger_sd_write(b)
#else
#define _LOG_SD_I(b)
#endif

#if LOG_SD_LEVEL >= LOG_LEVEL_WARN
#define _LOG_SD_W(b) logger_sd_write(b)
#else
#define _LOG_SD_W(b)
#endif

#if LOG_SD_LEVEL >= LOG_LEVEL_ERROR
#define _LOG_SD_E(b) logger_sd_write(b)
#else
#define _LOG_SD_E(b)
#endif

// ── Public macros ──────────────────────────────────────────────────────────
#if LOG_LEVEL >= LOG_LEVEL_INFO || LOG_SD_LEVEL >= LOG_LEVEL_INFO
#define LOG_I(tag, fmt, ...)                                           \
  do                                                                   \
  {                                                                    \
    char _b[192];                                                      \
    snprintf(_b, sizeof(_b), "[I][%s] " fmt, tag, ##__VA_ARGS__);     \
    _LOG_SER_I(_b);                                                    \
    _LOG_SD_I(_b);                                                     \
  } while (0)
#else
#define LOG_I(tag, fmt, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN || LOG_SD_LEVEL >= LOG_LEVEL_WARN
#define LOG_W(tag, fmt, ...)                                           \
  do                                                                   \
  {                                                                    \
    char _b[192];                                                      \
    snprintf(_b, sizeof(_b), "[W][%s] " fmt, tag, ##__VA_ARGS__);     \
    _LOG_SER_W(_b);                                                    \
    _LOG_SD_W(_b);                                                     \
  } while (0)
#else
#define LOG_W(tag, fmt, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR || LOG_SD_LEVEL >= LOG_LEVEL_ERROR
#define LOG_E(tag, fmt, ...)                                                    \
  do                                                                            \
  {                                                                             \
    char _b[192];                                                               \
    snprintf(_b, sizeof(_b), "[E][%s:%d] " fmt, tag, __LINE__, ##__VA_ARGS__); \
    _LOG_SER_E(_b);                                                             \
    _LOG_SD_E(_b);                                                              \
  } while (0)
#else
#define LOG_E(tag, fmt, ...)
#endif
