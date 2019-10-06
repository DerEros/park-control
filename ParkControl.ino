#include "libraries/Arduino-Log/ArduinoLog.h"

#include "App/App.h"

const unsigned int NUM_PIXELS = 8;

const unsigned int US_PERIOD_MILLIS = 200;
const unsigned int US_1_OFFSET_MILLIS = 10;

PeriodicMeasurement distance1(PIN_USOUND_TRIGGER_1, PIN_USOUND_ECHO_1, US_PERIOD_MILLIS, US_1_OFFSET_MILLIS);
App app;

void setup() {
    app.init();    
}

void loop() {
    app.loop();
/*    distance1.measure(deltaTimeMs);
    float us1Distance = distance1.getLastDistanceCM();
    
    CRGB color = 0;
    if (us1Distance > 50) {
        color = CRGB::Green; 
    } else if (us1Distance > 15) {
        color = CRGB::Yellow;
    } else {
        color = CRGB::Red;
    }

    fill_solid(leds, NUM_PIXELS, color);
    FastLED.show();
*/
}
