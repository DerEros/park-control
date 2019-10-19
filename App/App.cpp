#include "App.h"

#include "../libraries/Arduino-Log/ArduinoLog.h"
#include "Config.h"
#include "../AnimationBuilders/ParkControlAnimationBuilder.h"
#include "../Animations/IStatefulAnimation.h"

App::App() : state(ParkControlState(0)),
        distance1(PIN_USOUND_TRIGGER_1, PIN_USOUND_ECHO_1, US_PERIOD_MILLIS, US_1_OFFSET_MILLIS),
        motionDetector(1000, 9.0),
        timeOfLastMovementMillis(0)
{
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_TRACE, &Serial);

    Log.notice("Park Control - starting");
}

void App::init() {
    appClock.reset();
    pinMode(PIN_ENABLE_LOGIC_SHIFTER, OUTPUT);
    delay(2000);
    digitalWrite(PIN_ENABLE_LOGIC_SHIFTER, HIGH);

    files.start();
    network.start();
    config.load(files);
    configRestApi.start(state, files);

    leds = new CRGB[config.getNumLeds()];

    FastLED.addLeds<NEOPIXEL, PIN_LED_1>(leds, config.getNumLeds());

    if (config.getAnimationMode() == Config::PARK_CONTROL) {
        ParkControlAnimationBuilder animationBuilder(config);
        animation = animationBuilder.getStatefulAnimation(state);
    } else if (config.getAnimationMode() == Config::HALLOWEEN) {
    }
    renderer = new AnimationRenderer<CRGB>(*(animation), leds);
}

void App::loop() {
    unsigned int currentTime = millis();
    unsigned int elapsedTime = appClock.getElapsedTimeMillisAndReset();

    if (config.getAnimationMode() == Config::PARK_CONTROL) {
        distance1.measure(elapsedTime);
        state.distanceCM = (unsigned int)distance1.getLastDistanceCM();
        motionDetector.sample(elapsedTime, state.distanceCM);

        Log.verbose("Motion detected: %s \n ", (motionDetector.isMovementDetected()) ? "true" : "false");
        if (motionDetector.isMovementDetected()) {
            state.parkControlActive = true;
            timeOfLastMovementMillis = millis();
        } else {
            if (millis() - timeOfLastMovementMillis > config.getInactiveTimeout()) {
                state.parkControlActive = false;
            }
        }

        animation->setState(state);
        if (state.parkControlEnabled && state.parkControlActive) {
            renderer->render(elapsedTime);
        } else {
            FastLED.showColor(CRGB::Black, 0);
        }
    } else {

    }

    configRestApi.loop();
    delay(10);
}
