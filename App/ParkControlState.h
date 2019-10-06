#ifndef __STATE_H__
#define __STATE_H__

struct ParkControlState {
    unsigned int distanceCM;

    ParkControlState(unsigned int dist) : distanceCM(dist) {}
};

#endif
