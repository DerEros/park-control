#ifndef __MINIMAL_PIXEL_PATTERN_H__
#define __MINIMAL_PIXEL_PATTERN_H__

#include "AbstractPixelPattern.h"

template <typename TPixel>
class MinimalPixelPattern : public AbstractPixelPattern<TPixel> {
    public:
        MinimalPixelPattern(TPixel pixel) : AbstractPixelPattern<TPixel>(1), _pixel(pixel) {}

        const TPixel getPixel(int index) const { return _pixel; }
        unsigned int getLength() { return 1; }

    private:
        const TPixel _pixel;
};

#endif
