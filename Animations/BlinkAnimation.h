#ifndef __BLINK_ANIMATION_H__
#define __BLINK_ANIMATION_H__

#include "AbstractAnimation.h"

#include "IPixelPattern.h"

template <typename TPixel>
class BlinkAnimation : public AbstractAnimation<TPixel> {
    public:
        /**
         * @param range A range of pixels that this animation should cover
         * @param frequency The frequency in Hertz at which pixels should blink
         */
        BlinkAnimation(PixelRange range, float frequency, 
                IPixelPattern<TPixel> &patternOn, IPixelPattern<TPixel> &patternOff) :
                                                AbstractAnimation<TPixel>(range), 
                                                _frequency(frequency),
                                                _timePassendInPhase(0),
                                                _blinkPhase(OFF),
                                                _patternOn(patternOn),
                                                _patternOff(patternOff)
        {
            _phaseTimeInMs = 1.0 / frequency * 1000.0;
        }
        
        std::vector<TPixel> getPixels(unsigned int msSinceLastCall);

    private:
        enum BlinkPhase {
            OFF,
            ON
        };
        const float _frequency;
        float _phaseTimeInMs;
        unsigned int _timePassendInPhase;
        BlinkPhase _blinkPhase;

        const IPixelPattern<TPixel> &_patternOn;
        const IPixelPattern<TPixel> &_patternOff;

        void switchAnimationPhase();
        void resetPhaseTime();

        std::vector<TPixel> readPixels(const IPixelPattern<TPixel> &pattern);
};

#endif
