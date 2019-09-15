#ifndef __ABSTRACT_PIXEL_PATTERN_H_
#define __ABSTRACT_PIXEL_PATTERN_H_

#include "IPixelPattern.h"

template<typename TPixel>
class AbstractPixelPattern : public IPixelPattern<TPixel> {
    public:
        AbstractPixelPattern(unsigned int length) : _patternLenght(length) {};

        unsigned int getLength() { return _patternLenght; }

    private:
        unsigned int _patternLenght;
};

#endif
