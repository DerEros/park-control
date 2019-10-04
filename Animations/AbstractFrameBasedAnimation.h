#ifndef __ABSTRACT_FRAME_BASED_ANIMATION_H__
#define __ABSTRACT_FRAME_BASED_ANIMATION_H__

#include <Arduino.h>

#include "AbstractAnimation.h"

template <typename TPixel>
class AbstactFrameBasedAnimation : public AbstractAnimation<TPixel> {
    public:
        AbstactFrameBasedAnimation(PixelRange range, unsigned int framesPerSecond = 30) : 
            AbstractAnimation<TPixel>(range),
            _fps(framesPerSecond) {
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
