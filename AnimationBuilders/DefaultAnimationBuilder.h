#ifndef __DEFAULT_ANIMATION_BUILDER_H__
#define __DEFAULT_ANIMATION_BUILDER_H__

#include <Arduino.h>

#include "../Animations/IAnimation.h"
#include "../Animations/BlinkAnimation.h"

typedef uint32_t Pixel;

class DefaultAnimationBuilder {
    public:
        DefaultAnimationBuilder() {}

        IAnimation<uint32_t> *getAnimation();
};


#endif
