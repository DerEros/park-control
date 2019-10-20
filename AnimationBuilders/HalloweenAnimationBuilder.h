#ifndef __HALLOWEEN_ANIMATION_BUILDER_H__
#define __HALLOWEEN_ANIMATION_BUILDER_H__

#include <Arduino.h>

#include "../libraries/FastLED/FastLED.h"

#include "../Animations/IStatefulAnimation.h"
#include "../App/HalloweenState.h"

typedef CRGB Pixel;

class HalloweenAnimationBuilder {
    public:
        HalloweenAnimationBuilder() {}

        IStatefulAnimation<Pixel, HalloweenState>* getStatefulAnimation(HalloweenState& state);
    private:
};

#endif
