#include "libraries/Arduino-Log/ArduinoLog.h"
#include "libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.h"

Adafruit_NeoPixel pixels(8, D1, NEO_GRB + NEO_KHZ800);

void setup() {
    Serial.begin(9600);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    Log.notice("Park Control - starting");

    Log.verbose("Activating Pixels");
    pixels.begin();
}

int offset = 0;
void loop() {
    Log.verbose("Main loop starting");

    for (int i = 0; i < 8; i++) {
        if ((i + offset) % 3 == 0) {
            pixels.setPixelColor(i, 0x0000FF00);
        } else {
            pixels.setPixelColor(i, 0);
        }
    } 

    pixels.show();

    if (offset++ > 3) offset = 0;

    delay(200);
}
