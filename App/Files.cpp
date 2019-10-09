#include "Files.h"

#include "../libraries/Arduino-Log/ArduinoLog.h"

void Files::start() {
    Log.notice("SPIFFS starting");

    SPIFFS.begin();
}

String Files::getContentType(String filename) {
    if (filename.endsWith("html")) {
        return "text/html";
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
