#ifndef __RANGE_COMBINE_ANIMATION_H__
#define  __RANGE_COMBINE_ANIMATION_H__

#include <vector>
#include <numeric>
#include <algorithm>

#include <Arduino.h>

#include "IAnimation.h"

template <typename TPixel>
class RangeCombineAnimation : public IAnimation<TPixel> {
    public:
        RangeCombineAnimation(std::vector<IAnimation<TPixel>*> animations) : 
            _animations(animations),
            _range(PixelRange(0, 0))
        {
            auto rangeStartComparator = [](IAnimation<TPixel>* a, IAnimation<TPixel>* b) { return a->getRange().start < b->getRange().start; };

            auto earliestAnimation = std::min_element(_animations.begin(), _animations.end(), rangeStartComparator);
            std::sort(_animations.begin(), _animations.end(), rangeStartComparator);

            unsigned int numPixels = std::accumulate(_animations.begin(), _animations.end(), 0,
                        [](unsigned int acc, IAnimation<TPixel>* animation) {
                            return acc + animation->getRange().end - animation->getRange().start;
                        }
                    );
            
            if (earliestAnimation != _animations.end()) {
               int minRange = (*earliestAnimation)->getRange().start;
               _range = PixelRange(minRange, minRange + numPixels);
            }
        }

        virtual std::vector<TPixel> getPixels(unsigned int msSinceLastCall);
        
        virtual const PixelRange getRange() const {
            return _range;
        };
    private:
        PixelRange _range;
        std::vector<IAnimation<TPixel>*> _animations;

};

#endif
