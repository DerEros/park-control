#include "DefaultAnimationBuilder.h"

#include <vector>

#include "../Animations/MinimalPixelPattern.h"
#include "../Animations/SegmentPattern.h"
#include "../Animations/RepeatingPixelPattern.h"
#include "../Animations/BlinkAnimation.h"
#include "../Animations/SlideAnimation.h"
#include "../Animations/ConditionalAnimation.h"

IAnimation<Pixel> *DefaultAnimationBuilder::getAnimation() {
    std::vector<SegmentPattern<Pixel>::Segment> segments {
                    SegmentPattern<Pixel>::Segment(1, 0x0000FF00),
                    SegmentPattern<Pixel>::Segment(1, 0x00009900),
                    SegmentPattern<Pixel>::Segment(1, 0x00002200),
                    SegmentPattern<Pixel>::Segment(1, 0x00001200),
                    SegmentPattern<Pixel>::Segment(9, 0)
    };

    IPixelPattern<Pixel> *pattern = new RepeatingPixelPattern<Pixel>(new SegmentPattern<Pixel>(segments));

    SlideAnimation<Pixel> *ltr = new SlideAnimation<Pixel>(
            PixelRange(0, 8),
            24,
            *pattern,
            SlideAnimation<Pixel>::LEFT_TO_RIGHT
    );

    SlideAnimation<Pixel> *rtl = new SlideAnimation<Pixel>(
            PixelRange(0, 8),
            24,
            *pattern,
            SlideAnimation<Pixel>::RIGHT_TO_LEFT
    );

    auto condFuncEven = [](const unsigned int &i) { return (i / 5000) % 2 == 0; };
    auto condFuncUneven = [](const unsigned int &i) { return (i / 5000) % 2 == 1; };

    ConditionalAnimation<Pixel, unsigned int> *animation = new ConditionalAnimation<Pixel, unsigned int>(PixelRange(0, 8));
    animation->addCondition(condFuncEven, ltr);
    animation->addCondition(condFuncUneven, rtl);

    return animation;
}
