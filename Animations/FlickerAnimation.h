#ifndef __FLICKER_ANIMATION_H__
#define __FLICKER_ANIMATION_H__

#include "../libraries/FastLED/FastLED.h"

#include "AbstractFrameBasedAnimation.h"

class FlickerAnimation : public AbstractFrameBasedAnimation<CRGB> {
    public:
        FlickerAnimation(CRGBPalette256 &palette, PixelRange pixelRange, uint8_t flickerRate, unsigned int fps = 10) : 
            AbstractFrameBasedAnimation<CRGB>(pixelRange, fps),
                _palette(palette),
                _flickerRate(flickerRate)
        {
        }

    private:
        CRGBPalette256 _palette;
        std::vector<CRGB> _framePixels;
        std::vector<uint8_t> _paletteIdx;
        uint8_t _flickerRate;

        virtual void handleSwitchFrame();
        virtual std::vector<CRGB> getFramePixels();

        void flicker();
};

#endif
