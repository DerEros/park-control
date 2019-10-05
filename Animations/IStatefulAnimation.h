#ifndef __I_STATEFUL_ANIMATION_H__
#define __I_STATEFUL_ANIMATION_H__

#include "IAnimation.h"

template <typename TPixel, typename TState>
class IStatefulAnimation : public IAnimation<TPixel> {
    public:
        virtual void setState(TState& state) = 0;
};

#endif
