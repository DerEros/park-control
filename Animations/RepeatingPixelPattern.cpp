#include "RepeatingPixelPattern.h"

#include <Arduino.h>

template class RepeatingPixelPattern<uint32_t>;

template <typename TPixel>
const TPixel RepeatingPixelPattern<TPixel>::getPixel(int index) const {
    int normalizedIdx = index % _basePatternLength;

    return _basePattern->getPixel(normalizedIdx);
}
