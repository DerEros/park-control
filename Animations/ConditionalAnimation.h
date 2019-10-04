#ifndef __CONDITIONAL_ANIMATION_H__
#define __CONDITIONAL_ANIMATION_H__

#include <vector>

#include "AbstractAnimation.h"

template <typename TPixel, typename TInput>
struct If {
    bool(*condition)(const TInput&);
    IAnimation<TPixel> *animation;

    If(bool(*c)(const TInput&), IAnimation<TPixel> *a) : condition(c), animation(a) {}
};

template <typename TPixel, typename TInput>
class ConditionalAnimation : public AbstractAnimation<TPixel> {
    public:
        ConditionalAnimation(PixelRange range, std::vector<If<TPixel, TInput>> conditions) : 
            AbstractAnimation<TPixel>(range),
            _currentInput(0),
            _conditions(conditions) {}

        std::vector<TPixel> getPixels(unsigned int msSinceLastCall) {
            for (auto conditional : _conditions) {
                if (conditional.condition(*_currentInput)) {
                    return conditional.animation->getPixels(msSinceLastCall);
                }
            }
        }

        void setInput(TInput& input) { _currentInput = &input; }

    private:
        std::vector<If<TPixel, TInput>> _conditions;
        TInput* _currentInput;
};

#endif
