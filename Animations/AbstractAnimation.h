#include <vector>

#include "PixelRange.h"

#ifndef __ABSTRACT_ANIMATION_H__
#define __ABSTRACT_ANIMATION_H__

template <typename TPixel>
class AbstractAnimation {
    public:
        AbstractAnimation(PixelRange range) : _range(range) {}

        std::vector<TPixel> getPixels(unsigned int msSinceLastCall) = 0;

    private:
        PixelRange _range;
};

#endif
