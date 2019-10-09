#ifndef __APP_H__
#define __APP_H__

#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#include "../libraries/FastLED/FastLED.h"

#include "Pins.h"
#include "Config.h"
#include "ParkControlState.h"
#include "Network.h"
#include "ConfigRestApi.h"
#include "../Utils/Clock.h"
#include "Files.h"

#include "../Animations/AnimationRenderer.h"
#include "../Distances/PeriodicMeasurement.h"
#include "../Animations/IStatefulAnimation.h"

const unsigned int US_PERIOD_MILLIS = 200;
const unsigned int US_1_OFFSET_MILLIS = 10;

class App {
    public:
        App(); 

        void init();
        void loop();

    private:
        Clock appClock;
        Config config;
        ParkControlState state;
        Network network;
        Files files;
        ConfigRestApi configRestApi;

        AnimationRenderer<CRGB> *renderer;
        IStatefulAnimation<CRGB, ParkControlState> *animation;
        CRGB *leds;
        
        PeriodicMeasurement distance1;
};
#endif
