#ifndef FILE_SYSTEM_TYPE_h
#define FILE_SYSTEM_TYPE_h

#include "Boards.h"

#ifdef HAS_RNS

#define FS_TYPE_NONE 0
#define FS_TYPE_SPIFFS 1
#define FS_TYPE_INTERNALFS 2
#define FS_TYPE_LITTLEFS 3
#define FS_TYPE_FLASHFS 4

#if MCU_VARIANT == MCU_NRF52
    #include <Adafruit_LittleFS.h>
    #include <InternalFileSystem.h>
    using namespace Adafruit_LittleFS_Namespace;
    #define FS_TYPE FS_TYPE_INTERNALFS
    #define FS InternalFS
#elif MCU_VARIANT == MCU_ESP32
    #include <FS.h>
    #include <LittleFS.h>
    #define FS_TYPE FS_TYPE_LITTLEFS
    #define FS LittleFS
#else
    #define FS_TYPE FS_TYPE_NONE
#endif
#endif
#endif
