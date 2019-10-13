#include "App.h"

#include "../libraries/Arduino-Log/ArduinoLog.h"
#include "Config.h"
#include "../AnimationBuilders/ParkControlAnimationBuilder.h"
#include "../Animations/IStatefulAnimation.h"

App::App() : state(ParkControlState(0)),
        distance1(PIN_USOUND_TRIGGER_1, PIN_USOUND_ECHO_1, US_PERIOD_MILLIS, US_1_OFFSET_MILLIS)
{
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_NOTICE, &Serial);

    Log.notice("Park Control - starting");
}

void App::init() {
    Config config;
    appClock.reset();
    leds = new CRGB[config.getNumLeds()];

    FastLED.addLeds<NEOPIXEL, PIN_LED_1>(leds, config.getNumLeds());

    ParkControlAnimationBuilder animationBuilder(config);
    animation = animationBuilder.getStatefulAnimation(state);
    renderer = new AnimationRenderer<CRGB>(*(animation), leds);

    pinMode(PIN_ENABLE_LOGIC_SHIFTER, OUTPUT);
    delay(2000);
    digitalWrite(PIN_ENABLE_LOGIC_SHIFTER, HIGH);

    files.start();
    network.start();
    configRestApi.start(state, files);
}

void App::loop() {
    unsigned int currentTime = millis();
    unsigned int elapsedTime = appClock.getElapsedTimeMillisAndReset();

    distance1.measure(elapsedTime);
    state.distanceCM = (unsigned int)distance1.getLastDistanceCM();
    animation->setState(state);

    if (state.parkControlEnabled) {
        renderer->render(elapsedTime);
    } else {
        FastLED.showColor(CRGB::Black, 0);
    }

    configRestApi.loop();
    delay(10);
}
