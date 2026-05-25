# Range Training Screen — master

ESP32-S3 ekran treningowy dla strzelnicy. Komunikuje się z tarczami (slave) przez ESP-NOW.
UI zbudowane na LVGL 8 + LovyanGFX, konfiguracja tarcz ładowana z karty SD.

---

## Konfiguracja loggera

Wszystkie ustawienia w [`src/config.h`](src/config.h).

### LOG_LEVEL — logi na Serial

```c
#define LOG_LEVEL LOG_LEVEL_INFO
```

| Wartość | Znaczenie |
|---------|-----------|
| `LOG_LEVEL_NONE` (0) | żadnych logów na Serial |
| `LOG_LEVEL_ERROR` (1) | tylko błędy krytyczne (`LOG_E`) |
| `LOG_LEVEL_WARN` (2) | błędy + ostrzeżenia (`LOG_E`, `LOG_W`) |
| `LOG_LEVEL_INFO` (3) | wszystko: błędy, ostrzeżenia, informacje (`LOG_E`, `LOG_W`, `LOG_I`) |

### LOG_SD_LEVEL — logi na kartę SD

```c
#define LOG_SD_LEVEL LOG_LEVEL_WARN
```

Działa identycznie jak `LOG_LEVEL`, ale kieruje logi do pliku na karcie SD.
Możliwe wartości: `LOG_LEVEL_NONE` / `LOG_LEVEL_ERROR` / `LOG_LEVEL_WARN` / `LOG_LEVEL_INFO`.

Ustaw `LOG_LEVEL_NONE`, żeby całkowicie wyłączyć zapis na kartę.

### LOG_SD_FILE — ścieżka pliku logów

```c
constexpr const char* LOG_SD_FILE = "/log.txt";
```

Plik tworzony/dopisywany na korzeniu karty SD. Zmień ścieżkę według potrzeb.

### Przykłady konfiguracji

```c
// Produkcja: Serial cichy, na SD tylko błędy
#define LOG_LEVEL    LOG_LEVEL_NONE
#define LOG_SD_LEVEL LOG_LEVEL_ERROR

// Debugowanie: wszystko na Serial, nic na SD
#define LOG_LEVEL    LOG_LEVEL_INFO
#define LOG_SD_LEVEL LOG_LEVEL_NONE

// Domyślne: Serial pełny, SD tylko WARN + ERROR
#define LOG_LEVEL    LOG_LEVEL_INFO
#define LOG_SD_LEVEL LOG_LEVEL_WARN
```

> Decyzja o tym, co jest kompilowane, zapada w czasie kompilacji — nieużywane ścieżki
> nie generują żadnego kodu maszynowego.

---

## Konfiguracja tarcz — karta SD

Plik `/config.json` na korzeniu karty SD. Każda tarcza to wpis z 6-bajtowym adresem MAC
zapisanym jako tablica liczb dziesiętnych.

```json
{
  "shields": [
    { "mac": [60, 233, 14, 127, 48, 88] },
    { "mac": [AA, BB, CC, DD, EE, FF] }
  ]
}
```

Przeliczenie MAC hex → decimal:

| hex | dec |
|-----|-----|
| 0x3C | 60 |
| 0xE9 | 233 |
| 0x0E | 14 |
| 0xFF | 255 |

ID tarczy obliczane jest jako XOR trzech ostatnich oktetów MAC:
`id = mac[3] ^ mac[4] ^ mac[5]`.

---

## ESP-NOW

- Kanał: `ESPNOW_CHANNEL = 1` (stała w `config.h`)
- Slave musi mieć ten sam kanał skonfigurowany po swojej stronie
- Slave wysyła wiadomość do mastera po trafieniu; master identyfikuje tarczę po MAC nadawcy
