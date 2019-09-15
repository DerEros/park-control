#include "libraries/Arduino-Log/ArduinoLog.h"
#include "libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.h"

#include "AnimationBuilders/DefaultAnimationBuilder.h"
#include "Animations/AnimationRenderer.h"

Adafruit_NeoPixel pixels(8, D1, NEO_GRB + NEO_KHZ800);
AnimationRenderer<uint32_t> *renderer;
unsigned int previousMillis = 0;

void setup() {
    Serial.begin(9600);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    Log.notice("Park Control - starting");

    Log.verbose("Activating Pixels");
    pixels.begin();

    DefaultAnimationBuilder *animationBuilder = new DefaultAnimationBuilder();
    renderer = new AnimationRenderer<uint32_t>(*(animationBuilder->getAnimation()), pixels);

    previousMillis = millis();
}

void loop() {
    Log.verbose("Main loop starting");

    unsigned int currentTime = millis();
    unsigned int deltaTimeMs = currentTime - previousMillis;
    previousMillis = currentTime;

    renderer->render(deltaTimeMs);

    delay(2);
}
