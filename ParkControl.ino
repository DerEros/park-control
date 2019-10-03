#include "libraries/Arduino-Log/ArduinoLog.h"

#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#include "libraries/FastLED/FastLED.h"

#include "Pins.h"
#include "AnimationBuilders/DefaultAnimationBuilder.h"
#include "Animations/AnimationRenderer.h"
#include "Distances/PeriodicMeasurement.h"

const unsigned int NUM_PIXELS = 8;
AnimationRenderer<uint32_t> *renderer;
unsigned int previousMillis = 0;
CRGB leds[NUM_PIXELS];

const unsigned int US_PERIOD_MILLIS = 200;
const unsigned int US_1_OFFSET_MILLIS = 10;

PeriodicMeasurement distance1(PIN_USOUND_TRIGGER_1, PIN_USOUND_ECHO_1, US_PERIOD_MILLIS, US_1_OFFSET_MILLIS);

void setup() {
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    Log.notice("Park Control - starting");

    Log.verbose("Activating Pixels");
    FastLED.addLeds<NEOPIXEL, PIN_LED_1>(leds, NUM_PIXELS);

    DefaultAnimationBuilder *animationBuilder = new DefaultAnimationBuilder();
    renderer = new AnimationRenderer<uint32_t>(*(animationBuilder->getAnimation()), leds);

    previousMillis = millis();

    pinMode(PIN_ENABLE_LOGIC_SHIFTER, OUTPUT);
    delay(2000);
    digitalWrite(PIN_ENABLE_LOGIC_SHIFTER, HIGH);
}

void loop() {

    unsigned int currentTime = millis();
    unsigned int deltaTimeMs = currentTime - previousMillis;
    previousMillis = currentTime;

    renderer->render(deltaTimeMs);
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
    delay(10);
}
