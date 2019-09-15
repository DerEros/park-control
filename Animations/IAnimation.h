#ifndef __I_ANIMATION_H__
#define __I_ANIMATION_H__ 

#include <vector>

#include "PixelRange.h"

template <typename TPixel>
class IAnimation {
    public:
        virtual std::vector<TPixel> getPixels(unsigned int msSinceLastCall) = 0;
        virtual const PixelRange getRange() const = 0;
};

#endif
