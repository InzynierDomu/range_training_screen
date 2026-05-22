#pragma once

#include "config.h"

#include <Arduino.h>

#if LOG_LEVEL >= LOG_LEVEL_INFO
#define LOG_I(tag, fmt, ...) Serial.printf("[I][%s] " fmt "\n", tag, ##__VA_ARGS__)
#else
#define LOG_I(tag, fmt, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#define LOG_W(tag, fmt, ...) Serial.printf("[W][%s] " fmt "\n", tag, ##__VA_ARGS__)
#else
#define LOG_W(tag, fmt, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR
#define LOG_E(tag, fmt, ...) Serial.printf("[E][%s:%d] " fmt "\n", tag, __LINE__, ##__VA_ARGS__)
#else
#define LOG_E(tag, fmt, ...)
#endif
