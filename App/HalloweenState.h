#ifndef __HALLOWEEN_STATE_H__
#define __HALLOWEEN_STATE_H__

struct HalloweenState {
    bool spookyMode;

    HalloweenState(bool initialSpookyMode) : spookyMode(initialSpookyMode)
    {}
};

#endif
