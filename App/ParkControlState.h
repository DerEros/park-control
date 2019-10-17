#ifndef __STATE_H__
#define __STATE_H__

struct ParkControlState {
    unsigned int distanceCM;
    bool parkControlEnabled;
    bool parkControlActive;

    ParkControlState(unsigned int dist) : 
        distanceCM(dist),
        parkControlEnabled(true),
        parkControlActive(true)
    {}
};

#endif
