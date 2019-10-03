#include "SlideAnimation.h"
#include <Arduino.h>

template class SlideAnimation<uint32_t>;

template <typename TPixel>
std::vector<TPixel> SlideAnimation<TPixel>::getPixels(unsigned int msSinceLastCall) {
    std::vector<TPixel> renderedPixels;

    advanceAnimation(msSinceLastCall);

    if (slideDirection == LEFT_TO_RIGHT) {
        getPixelsLtr(renderedPixels);
    } else {
        getPixelsRtl(renderedPixels);
    }
    return renderedPixels;
}

template <typename TPixel>
void SlideAnimation<TPixel>::advanceAnimation(unsigned int msSinceLastCall) {
    timeInFrame += msSinceLastCall;

    if (timeInFrame > frameLengthMs) {
        while (timeInFrame > frameLengthMs) {
            timeInFrame -= frameLengthMs;
        }

        patternOffset++;
    }
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
