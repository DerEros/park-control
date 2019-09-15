#ifndef __ANIMATION_RENDERER_H__
#define __ANIMATION_RENDERER_H__

#include "../libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include "../libraries/Arduino-Log/ArduinoLog.h"
#include "IAnimation.h"

typedef Adafruit_NeoPixel PixelOut;

template <typename TPixel>
class AnimationRenderer {
    public:
        AnimationRenderer(IAnimation<TPixel> &animation, PixelOut &out) : _animation(animation), _out(out) {} 

        void render(unsigned int deltaTimeMs);

    private:
        IAnimation<TPixel> &_animation;
        PixelOut &_out;
};

#endif
