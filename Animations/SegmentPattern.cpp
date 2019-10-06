#include "SegmentPattern.h"

#include <Arduino.h>

#include "../libraries/FastLED/FastLED.h"

template class SegmentPattern<uint32_t>;
template class SegmentPattern<CRGB>;

template <typename TPixel>
const TPixel SegmentPattern<TPixel>::getPixel(int index) const {
    unsigned int currentSegmentBasePixelIdx = 0;
    Segment currentSegment = _segments.at(0); // throw if no segments present at all

    for (Segment currentSegment : _segments) {
        if (currentSegmentBasePixelIdx + currentSegment.numPixels > index) {
            return currentSegment.color;
        }
        currentSegmentBasePixelIdx += currentSegment.numPixels;
    }

    return currentSegment.color;
}
