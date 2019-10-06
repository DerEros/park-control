#include "SlideAnimation.h"
#include <Arduino.h>

#include "../libraries/FastLED/FastLED.h"

template class SlideAnimation<uint32_t>;
template class SlideAnimation<CRGB>;

template <typename TPixel>
std::vector<TPixel> SlideAnimation<TPixel>::getFramePixels() {
    std::vector<TPixel> renderedPixels;

    if (slideDirection == LEFT_TO_RIGHT) {
        getPixelsLtr(renderedPixels);
    } else {
        getPixelsRtl(renderedPixels);
    }
    return renderedPixels;
}

template <typename TPixel>
void SlideAnimation<TPixel>::handleSwitchFrame() {
    patternOffset++;
}

template <typename TPixel>
void SlideAnimation<TPixel>::getPixelsLtr(std::vector<TPixel> &out) {
    for (int targetIdx = 0; targetIdx < this->getRange().length(); targetIdx++) {
        out.push_back(slidePattern.getPixel(targetIdx + patternOffset));
    }
}

template <typename TPixel>
void SlideAnimation<TPixel>::getPixelsRtl(std::vector<TPixel> &out) {
    for (int targetIdx = this->getRange().length() - 1; targetIdx >= 0 ; targetIdx--) {
        out.push_back(slidePattern.getPixel(targetIdx + patternOffset));
    }
}
