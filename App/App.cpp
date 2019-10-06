#include "App.h"

#include "../libraries/Arduino-Log/ArduinoLog.h"
#include "Config.h"
#include "../AnimationBuilders/ParkControlAnimationBuilder.h"
#include "../Animations/IStatefulAnimation.h"

App::App() : state(ParkControlState(0)) {
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    Log.notice("Park Control - starting");
}

void App::init() {
    Config config;
    appClock.reset();
    leds = new CRGB[config.getNumLeds()];

    FastLED.addLeds<NEOPIXEL, PIN_LED_1>(leds, config.getNumLeds());
/*
    DefaultAnimationBuilder *animationBuilder = new DefaultAnimationBuilder();
    animation = static_cast<ConditionalAnimation<uint32, unsigned int>*>(animationBuilder->getAnimation());
    */

    ParkControlAnimationBuilder animationBuilder(config);
    animation = animationBuilder.getStatefulAnimation(state);
    renderer = new AnimationRenderer<CRGB>(*(animation), leds);

    pinMode(PIN_ENABLE_LOGIC_SHIFTER, OUTPUT);
    delay(2000);
    digitalWrite(PIN_ENABLE_LOGIC_SHIFTER, HIGH);
}

void App::loop() {
    unsigned int currentTime = millis();
    animation->setState(state);
    renderer->render(appClock.getElapsedTimeMillisAndReset());

    delay(10);
}
