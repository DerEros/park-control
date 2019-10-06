#ifndef __ABSTRACT_FRAME_BASED_ANIMATION_H__
#define __ABSTRACT_FRAME_BASED_ANIMATION_H__

#include <Arduino.h>

#include "AbstractAnimation.h"

template <typename TPixel>
class AbstractFrameBasedAnimation : public AbstractAnimation<TPixel> {
    public:
        AbstractFrameBasedAnimation(PixelRange range, unsigned int framesPerSecond = 30) : 
            AbstractAnimation<TPixel>(range),
            _timeSinceLastFrameMillis(0),
            _fps(framesPerSecond) 
        {
            _lastFrameStartMillis = millis();
            _timePerFrameMillis = 1000.0 / (float)framesPerSecond;
        }

        unsigned int getFramesPerSecond() const { return _fps; }

        virtual std::vector<TPixel> getPixels(unsigned int msSinceLastCall);

    private:
        unsigned int _fps;
        unsigned int _lastFrameStartMillis;
        unsigned int _timeSinceLastFrameMillis;

        float _timePerFrameMillis;

        virtual void handleSwitchFrame() = 0;
        virtual std::vector<TPixel> getFramePixels() = 0;
};

#endif
