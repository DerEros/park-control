#ifndef __PARK_CONTROL_ANIMATION_BUILDER_H__
#define __PARK_CONTROL_ANIMATION_BUILDER_H__

#include <Arduino.h>

#include "../libraries/FastLED/FastLED.h"

#include "../App/Config.h"
#include "../App/ParkControlState.h"
#include "../Animations/IStatefulAnimation.h"

typedef CRGB Pixel;
typedef ParkControlState State;

class ParkControlAnimationBuilder {
    public:
        ParkControlAnimationBuilder(Config& config) : _config(config) {}

        IStatefulAnimation<Pixel, State>* getStatefulAnimation(State& state);

    private:
        Config& _config;
};

#endif
