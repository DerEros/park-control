#include "SlideAnimation.h"
#include <Arduino.h>

template class SlideAnimation<uint32_t>;

template <typename TPixel>
std::vector<TPixel> SlideAnimation<TPixel>::getPixels(unsigned int msSinceLastCall) {
    std::vector<TPixel> renderedPixels(this->getRange().length());
}

template <typename TPixel>
void SlideAnimation<TPixel>::getPixelsLtr(std::vector<TPixel> &out) {
    for (unsigned int targetIdx = 0; targetIdx < this->getRange().length(); targetIdx++) {
        out.push_back(slidePattern.getPixel(targetIdx + patternOffset));
    }
}

template <typename TPixel>
void SlideAnimation<TPixel>::getPixelsRtl(std::vector<TPixel> &out) {
    for (unsigned int targetIdx = this->getRange().length(); targetIdx > 0 ; targetIdx--) {
        out.push_back(slidePattern.getPixel(targetIdx + patternOffset));
    }
}
