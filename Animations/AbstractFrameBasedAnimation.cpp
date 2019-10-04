#include "AbstractFrameBasedAnimation.h"

template class AbstactFrameBasedAnimation<uint32_t>;

template <typename TPixel>
std::vector<TPixel> AbstactFrameBasedAnimation<TPixel>::getPixels(unsigned int msSinceLastCall) {
    _timeSinceLastFrameMillis += msSinceLastCall;

    while (_timeSinceLastFrameMillis > _timePerFrameMillis) {
        handleSwitchFrame();
        _timeSinceLastFrameMillis -= _timePerFrameMillis;
    }

    getFramePixels();
}
