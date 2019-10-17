#include "Files.h"

#include "../libraries/Arduino-Log/ArduinoLog.h"

void Files::start() {
    Log.notice("SPIFFS starting\n");

    SPIFFS.begin();

    Log.trace("SPIFFS started\n");
}

String Files::getContentType(String filename) {
    if (filename.endsWith("html")) {
        return "text/html";
    } else if (filename.endsWith("js")) {
        return "application/javascript";
    } else {
        return "text/plain";
    }
}

bool Files::fileExists(String filename) {
    return SPIFFS.exists(filename);
}

File Files::getFileForRead(String filename) {
    return SPIFFS.open(filename, "r");
}

File Files::getFileForWrite(String filename) {
    return SPIFFS.open(filename, "w");
}
