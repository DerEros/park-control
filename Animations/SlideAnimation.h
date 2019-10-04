#ifndef __SLIDE_ANIMATION_H__
#define  __SLIDE_ANIMATION_H__ 

#include "AbstractFrameBasedAnimation.h"
#include "IPixelPattern.h"

template<typename TPixel>
class SlideAnimation : public AbstractFrameBasedAnimation<TPixel> {
    public:
        enum Direction {
            LEFT_TO_RIGHT,
            RIGHT_TO_LEFT
        };

        SlideAnimation(PixelRange range, unsigned int framesPerSecond,
                IPixelPattern<TPixel> &pattern, Direction dir = LEFT_TO_RIGHT
                ) :
            AbstractFrameBasedAnimation<TPixel>(range, framesPerSecond),
            slidePattern(pattern),
            slideDirection(dir),
            patternOffset(0)
        {}

    private:
        Direction slideDirection;
        const IPixelPattern<TPixel> &slidePattern;

        unsigned int patternOffset;

        virtual void handleSwitchFrame();
        virtual std::vector<TPixel> getFramePixels();

        void getPixelsLtr(std::vector<TPixel> &out);
        void getPixelsRtl(std::vector<TPixel> &out);
};

#endif
