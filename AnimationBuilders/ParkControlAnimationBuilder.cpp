#include "ParkControlAnimationBuilder.h"

#include <vector>

#include "../libraries/Arduino-Log/ArduinoLog.h"

#include "../Animations/PixelRange.h"
#include "../Animations/IPixelPattern.h"
#include "../Animations/IAnimation.h"
#include "../Animations/MinimalPixelPattern.h"
#include "../Animations/SegmentPattern.h"
#include "../Animations/RepeatingPixelPattern.h"
#include "../Animations/SlideAnimation.h"
#include "../Animations/BlinkAnimation.h"
#include "../Animations/RangeCombineAnimation.h"
#include "../Animations/ConditionalAnimation.h"

IPixelPattern<Pixel>* getFadePattern(int hue, int fadeSteps, int emptyPixels);
IPixelPattern<Pixel>* getSolidPattern(int hue);
IPixelPattern<Pixel>* getWhitePattern();
IPixelPattern<Pixel>* getBlankPattern();

IAnimation<Pixel>* getTooFarAnimation(PixelRange leftRange, PixelRange rightRange, unsigned int fps);
IAnimation<Pixel>* getCloseAnimation(PixelRange leftRange, PixelRange rightRange, unsigned int fps);

IStatefulAnimation<Pixel, State>* ParkControlAnimationBuilder::getStatefulAnimation(State& state) {
    Log.notice("Creating animations");

    Config *config = &this->_config;

    unsigned int numLeds = config->getNumLeds();
    unsigned int lastLedIdx = numLeds - 1;
    PixelRange fullRange(0, lastLedIdx);
    PixelRange leftRange(0, lastLedIdx / 2);
    PixelRange rightRange(lastLedIdx / 2 + 1, lastLedIdx);

    IPixelPattern<Pixel> *greenSolidPattern = getSolidPattern(HUE_GREEN);
    IPixelPattern<Pixel> *redSolidPattern = getSolidPattern(HUE_RED);
    IPixelPattern<Pixel> *whiteSolidPattern = getWhitePattern();
    IPixelPattern<Pixel> *blankPattern = getBlankPattern();

    IAnimation<Pixel>* greenBlinkAnimation = new BlinkAnimation<Pixel>(
            fullRange, 3, *greenSolidPattern, *blankPattern);

    IAnimation<Pixel>* redBlinkAnimation = new BlinkAnimation<Pixel>(
            fullRange, 3, *redSolidPattern, *blankPattern);

    IAnimation<Pixel>* whiteBlinkAnimation = new BlinkAnimation<Pixel>(
            fullRange, 3, *whiteSolidPattern, *blankPattern);

    ConditionalAnimation<Pixel, State>* parkControlAnimation = 
        new ConditionalAnimation<Pixel, State>(fullRange, state);

    parkControlAnimation->addCondition(
            [](const State& s){ return s.distanceCM > 50; },
            getTooFarAnimation(leftRange, rightRange, config->getAnimationFps()));
    parkControlAnimation->addCondition(
            [](const State& s){ return s.distanceCM > 40; },
            greenBlinkAnimation);
    parkControlAnimation->addCondition(
            [](const State& s){ return s.distanceCM > 15; },
            getCloseAnimation(leftRange, rightRange, config->getAnimationFps()));
    parkControlAnimation->addCondition(
            [](const State& s){ return s.distanceCM > 0; },
            redBlinkAnimation);
    parkControlAnimation->addCondition(
            [](const State& s){ return true; },
            whiteBlinkAnimation);

    return parkControlAnimation;
}

IPixelPattern<Pixel> *getFadePattern(int hue, int fadeSteps, int emptyPixels) {
    std::vector<SegmentPattern<Pixel>::Segment> segments;
    for (int idx = 0; idx < fadeSteps; idx++) {
        int value = 255 - (idx * (255 / fadeSteps));

        segments.push_back(SegmentPattern<Pixel>::Segment(1, CHSV(hue, 255, value)));
    }
    segments.push_back(SegmentPattern<Pixel>::Segment(emptyPixels, CHSV(hue, 255, 0)));

    return new RepeatingPixelPattern<Pixel>(new SegmentPattern<Pixel>(segments));
}

IPixelPattern<Pixel>* getSolidPattern(int hue) {
    return new MinimalPixelPattern<Pixel>(CHSV(hue, 255, 255));
}

IPixelPattern<Pixel>* getWhitePattern() {
    return new MinimalPixelPattern<Pixel>(CRGB::White);
}

IPixelPattern<Pixel>* getBlankPattern() {
    return new MinimalPixelPattern<Pixel>(CRGB::Black);
}

IAnimation<Pixel>* getTooFarAnimation(PixelRange leftRange, PixelRange rightRange, unsigned int fps) {
    IPixelPattern<Pixel> *blueFadePattern = getFadePattern(HUE_BLUE, 4, 9);

    IAnimation<Pixel>* blueSlideLeft = new SlideAnimation<Pixel>(
        leftRange, fps, *blueFadePattern, SlideAnimation<Pixel>::LEFT_TO_RIGHT
    );
    IAnimation<Pixel>* blueSlideRight = new SlideAnimation<Pixel>(
        rightRange, fps, *blueFadePattern, SlideAnimation<Pixel>::RIGHT_TO_LEFT
    );
    return new RangeCombineAnimation<Pixel>(std::vector<IAnimation<Pixel>*>{ blueSlideLeft, blueSlideRight });
}

IAnimation<Pixel>* getCloseAnimation(PixelRange leftRange, PixelRange rightRange, unsigned int fps) {
    IPixelPattern<Pixel> *yellowFadePattern = getFadePattern(HUE_YELLOW, 4, 9);

    IAnimation<Pixel>* yellowSlideLeft = new SlideAnimation<Pixel>(
        leftRange, fps, *yellowFadePattern, SlideAnimation<Pixel>::RIGHT_TO_LEFT
    );
    IAnimation<Pixel>* yellowSlideRight = new SlideAnimation<Pixel>(
        rightRange, fps, *yellowFadePattern, SlideAnimation<Pixel>::LEFT_TO_RIGHT
    );
    return new RangeCombineAnimation<Pixel>(std::vector<IAnimation<Pixel>*>{ yellowSlideLeft, yellowSlideRight });
}
