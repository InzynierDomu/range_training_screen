#include "logger.h"
#include "config.h"

#include <SD.h>

#if LOG_SD_LEVEL > LOG_LEVEL_NONE
void logger_sd_write(const char* entry)
{
  File f = SD.open(LOG_SD_FILE, FILE_APPEND);
  if (!f)
    return;
  f.println(entry);
  f.close();
}
#endif
