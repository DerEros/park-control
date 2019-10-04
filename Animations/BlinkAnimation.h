#ifndef __BLINK_ANIMATION_H__
#define __BLINK_ANIMATION_H__

#include "AbstractFrameBasedAnimation.h"

#include "IPixelPattern.h"

template <typename TPixel>
class BlinkAnimation : public AbstractFrameBasedAnimation<TPixel> {
    public:
        /**
         * @param range A range of pixels that this animation should cover
         * @param frequency The frequency in Hertz at which pixels should blink
         */
        BlinkAnimation(PixelRange range, unsigned int frequency, 
                IPixelPattern<TPixel> &patternOn, IPixelPattern<TPixel> &patternOff) :
                                                AbstractFrameBasedAnimation<TPixel>(range, frequency), 
                                                _blinkPhase(OFF),
                                                _patternOn(patternOn),
                                                _patternOff(patternOff)
        {
        }
        
    private:
        enum BlinkPhase {
            OFF,
            ON
        };
        BlinkPhase _blinkPhase;

        const IPixelPattern<TPixel> &_patternOn;
        const IPixelPattern<TPixel> &_patternOff;

        std::vector<TPixel> readPixels(const IPixelPattern<TPixel> &pattern);
};

#endif
