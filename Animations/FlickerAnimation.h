#ifndef __FLICKER_ANIMATION_H__
#define __FLICKER_ANIMATION_H__

#include "../libraries/FastLED/FastLED.h"

#include "AbstractFrameBasedAnimation.h"

class FlickerAnimation : public AbstractFrameBasedAnimation<CRGB> {
    public:
        FlickerAnimation(CRGBPalette256 &palette, PixelRange pixelRange, unsigned int fps = 10) : 
            AbstractFrameBasedAnimation<CRGB>(pixelRange, fps),
                _palette(palette)
        {}

    private:
        CRGBPalette256 _palette;
        std::vector<CRGB> _framePixels;

        virtual void handleSwitchFrame();
        virtual std::vector<CRGB> getFramePixels();
};

#endif
