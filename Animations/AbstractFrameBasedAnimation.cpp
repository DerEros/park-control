#include "AbstractFrameBasedAnimation.h"

#include "../libraries/FastLED/FastLED.h"

template class AbstractFrameBasedAnimation<uint32_t>;
template class AbstractFrameBasedAnimation<CRGB>;

template <typename TPixel>
std::vector<TPixel> AbstractFrameBasedAnimation<TPixel>::getPixels(unsigned int msSinceLastCall) {
    _timeSinceLastFrameMillis += msSinceLastCall;

    while (_timeSinceLastFrameMillis > _timePerFrameMillis) {
        handleSwitchFrame();
        _timeSinceLastFrameMillis -= _timePerFrameMillis;
    }

    return getFramePixels();
}
