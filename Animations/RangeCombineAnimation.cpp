#include "RangeCombineAnimation.h"

#include <algorithm>

#include <Arduino.h>

template class RangeCombineAnimation<uint32_t>;

template <typename TPixel>
std::vector<TPixel> RangeCombineAnimation<TPixel>::getPixels(unsigned int msSinceLastCall) {
    std::vector<TPixel> pixels;

    for (IAnimation<TPixel> * animation : _animations) {
        std::vector<TPixel> animationsPixels = animation->getPixels(msSinceLastCall);
        pixels.insert(pixels.end(), animationsPixels.begin(), animationsPixels.end());
    }

    return pixels;
}
