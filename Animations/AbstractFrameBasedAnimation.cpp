#include "AbstractFrameBasedAnimation.h"

template class AbstractFrameBasedAnimation<uint32_t>;

template <typename TPixel>
std::vector<TPixel> AbstractFrameBasedAnimation<TPixel>::getPixels(unsigned int msSinceLastCall) {
    _timeSinceLastFrameMillis += msSinceLastCall;

    while (_timeSinceLastFrameMillis > _timePerFrameMillis) {
        handleSwitchFrame();
        _timeSinceLastFrameMillis -= _timePerFrameMillis;
    }

    return getFramePixels();
}
