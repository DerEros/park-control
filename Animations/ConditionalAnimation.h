#ifndef __CONDITIONAL_ANIMATION_H__
#define __CONDITIONAL_ANIMATION_H__

#include <vector>
#include <utility>

#include "AbstractStatefulAnimation.h"

template <typename TPixel, typename TInput>
class ConditionalAnimation : public AbstractStatefulAnimation<TPixel, TInput> {
    public:
        ConditionalAnimation(PixelRange range, TInput &initialState) : 
            AbstractStatefulAnimation<TPixel, TInput>(range, initialState) {}

        std::vector<TPixel> getPixels(unsigned int msSinceLastCall) {
            for (auto conditional : _conditions) {
                if (conditional.first(this->getState())) {
                    return conditional.second->getPixels(msSinceLastCall);
                }
            }
        }

        typedef bool(*Condition)(const TInput&);

        void addCondition(Condition condition, IAnimation<TPixel> *animation) {
            _conditions.push_back(std::pair<Condition, IAnimation<TPixel>*>(condition, animation));
        }

    private:
        std::vector<std::pair<Condition, IAnimation<TPixel> * >> _conditions;
};

#endif
