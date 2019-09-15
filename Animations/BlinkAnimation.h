#include "AbstractAnimation.h"

#ifndef __BLINK_ANIMATION_H__
#define __BLINK_ANIMATION_H__

template <typename TPixel>
class BlinkAnimation : AbstractAnimation<TPixel> {
    public:
        /**
         * @param range A range of pixels that this animation should cover
         * @param frequency The frequency in Hertz at which pixels should blink
         */
        BlinkAnimation(PixelRange range, float frequency) : AbstractAnimation<TPixel>(range), 
                                                            _frequency(frequency),
                                                            _timePassendInPhase(0),
                                                            _blinkPhase(OFF)
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
        const float _phaseTimeInMs;
        unsigned int _timePassendInPhase;
        BlinkPhase _blinkPhase;

        void switchAnimationPhase();
        void resetPhaseTime();
};

#endif
