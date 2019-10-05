#ifndef __CONDITIONAL_ANIMATION_H__
#define __CONDITIONAL_ANIMATION_H__

#include <vector>
#include <utility>

#include "AbstractAnimation.h"

template <typename TPixel, typename TInput>
class ConditionalAnimation : public AbstractAnimation<TPixel> {
    public:
        ConditionalAnimation(PixelRange range) : 
            AbstractAnimation<TPixel>(range),
            _currentInput(0) {}

        std::vector<TPixel> getPixels(unsigned int msSinceLastCall) {
            for (auto conditional : _conditions) {
                if (conditional.first(*_currentInput)) {
                    return conditional.second->getPixels(msSinceLastCall);
                }
            }
        }

        typedef bool(*Condition)(const TInput&);

        void setInput(TInput& input) { _currentInput = &input; }
        void addCondition(Condition condition, IAnimation<TPixel> *animation) {
            _conditions.push_back(std::pair<Condition, IAnimation<TPixel>*>(condition, animation));
        }

    private:
        std::vector<std::pair<Condition, IAnimation<TPixel> * >> _conditions;
        TInput* _currentInput;
};

#endif
