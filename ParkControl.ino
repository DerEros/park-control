#include "libraries/Arduino-Log/ArduinoLog.h"

#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#include "libraries/FastLED/FastLED.h"

#define PIN_LED 1
#define PIN_ENABLE_LOGIC_SHIFTER 3

#include "AnimationBuilders/DefaultAnimationBuilder.h"
#include "Animations/AnimationRenderer.h"

const unsigned int NUM_PIXELS = 8;
AnimationRenderer<uint32_t> *renderer;
unsigned int previousMillis = 0;
CRGB leds[NUM_PIXELS];

void setup() {
    Serial.begin(9600);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    Log.notice("Park Control - starting");

    Log.verbose("Activating Pixels");
    FastLED.addLeds<NEOPIXEL, PIN_LED>(leds, NUM_PIXELS);

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

    delay(2);
}
