#ifndef __REPEATING_PIXEL_PATTERN_H__
#define  __REPEATING_PIXEL_PATTERN_H__

#include "IPixelPattern.h"

#include <limits.h>

template<typename TPixel>
class RepeatingPixelPattern : public IPixelPattern<TPixel> {
    public:
        RepeatingPixelPattern(IPixelPattern<TPixel> *basePattern) : 
            _basePattern(basePattern)
        {
            _basePatternLength = basePattern->getLength();
        };

        unsigned int getLength() { return UINT_MAX; }
        const TPixel getPixel(int index) const; 

    private:
        IPixelPattern<TPixel> *_basePattern; 
        unsigned int _basePatternLength;
};

#endif
