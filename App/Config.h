#ifndef __CONFIG_H__
#define __CONFIG_H__

class Config {
    public:
        Config() {
            numLeds = 8;
            minMoveFurtherDistance = 50;
            minIdealDistance = 40;
            minMoveFurtherDistance = 15;
            minCriticalCloseDistance = 0;

            animationFps = 24;
        }
        void load() {};

        unsigned int getNumLeds() { return numLeds; }
        unsigned int getMinMoveCloserDistance() { return minMoveCloserDistance; }
        unsigned int getMinIdealDistance() { return minIdealDistance; }
        unsigned int getMinMoveFurtherDistance() { return minMoveFurtherDistance; }
        unsigned int getMinCriticalCloseDistance() { return minCriticalCloseDistance; }

        unsigned int getAnimationFps() { return animationFps; }

    private:
        unsigned int numLeds;
        unsigned int minMoveCloserDistance;
        unsigned int minIdealDistance;
        unsigned int minMoveFurtherDistance;
        unsigned int minCriticalCloseDistance;

        unsigned int animationFps;
};
#endif
