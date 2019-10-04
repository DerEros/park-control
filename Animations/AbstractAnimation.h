
#ifndef __ABSTRACT_ANIMATION_H__
#define __ABSTRACT_ANIMATION_H__

#include <vector>

#include "IAnimation.h"
#include "PixelRange.h"

template <typename TPixel>
class AbstractAnimation : public IAnimation<TPixel> {
    public:
        AbstractAnimation(PixelRange range) : _range(range) {}

        const PixelRange getRange() const { return _range; };
    private:
        PixelRange _range;
};

#endif
