#ifndef __STATEFUL_ANIMATION_RENDERER_H__
#define  __STATEFUL_ANIMATION_RENDERER_H__

#include "AnimationRenderer.h"
#include "IStatefulAnimation.h"

template <typename TPixel, typename TInput>
class StatefulAnimationRenderer : public AnimationRenderer<TPixel> {
    public:
        StatefulAnimationRenderer(IStatefulAnimation<TPixel, TInput> &animation, PixelOut out) :
            _animation(animation), _out(out) {}

    private:
        IStatefulAnimation<TPixel, TInput> &_animation;
        PixelOut _out;
};
#endif 
