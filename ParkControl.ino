#include "libraries/Arduino-Log/ArduinoLog.h"
#include "libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.h"

void setup() {
    Serial.begin(9600);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    Log.notice("Park Control - starting");
}

void loop() {
    Log.verbose("Main loop starting");
}
