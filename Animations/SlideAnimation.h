#ifndef __SLIDE_ANIMATION_H__
#define  __SLIDE_ANIMATION_H__ 

#include "AbstractAnimation.h"
#include "IPixelPattern.h"

template<typename TPixel>
class SlideAnimation : public AbstractAnimation<TPixel> {
    public:
        enum Direction {
            LEFT_TO_RIGHT,
            RIGHT_TO_LEFT
        };

        SlideAnimation(PixelRange range, float frequency,
                IPixelPattern<TPixel> &pattern, Direction dir = LEFT_TO_RIGHT
                ) :
            AbstractAnimation<TPixel>(range),
            slidePattern(pattern),
            slideDirection(dir),
            timeInFrame(0),
            patternOffset(0)
        {
            frameLengthMs = 1000.0 / frequency;
        }

        std::vector<TPixel> getPixels(unsigned int msSinceLastCall);

    private:
        Direction slideDirection;
        const IPixelPattern<TPixel> &slidePattern;

        float frameLengthMs;
        unsigned int timeInFrame;

        unsigned int patternOffset;

        void advanceAnimation(unsigned int msSinceLastCall);
        void getPixelsLtr(std::vector<TPixel> &out);
        void getPixelsRtl(std::vector<TPixel> &out);
};

#endif
