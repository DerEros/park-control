#ifndef __ABSTRACT_STATEFUL_ANIMATION_H__
#define __ABSTRACT_STATEFUL_ANIMATION_H__

#include "IStatefulAnimation.h"

template <typename TPixel, typename TState>
class AbstractStatefulAnimation : public IStatefulAnimation<TPixel, TState> {
    public:
        AbstractStatefulAnimation(PixelRange range, TState& initialState) : 
            _range(range),
            _state(initialState) {}

        const PixelRange getRange() const { return _range; };
        virtual void setState(TState& state) {
            this->_state = state;
        };

        TState& getState() { return _state; };
    private:
        PixelRange _range;
        TState &_state;
};
#endif
