#ifndef __HALLOWEEN_ANIMATION_BUILDER_H__
#define __HALLOWEEN_ANIMATION_BUILDER_H__

#include <Arduino.h>

#include "../libraries/FastLED/FastLED.h"

#include "../Animations/IAnimation.h"

typedef CRGB Pixel;

class HalloweenAnimationBuilder {
    public:
        HalloweenAnimationBuilder() {}

        IAnimation<Pixel>* getAnimation();
    private:
};

#endif
