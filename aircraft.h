#ifndef AIRCRAFT_H_INCLUDED
#define AIRCRAFT_H_INCLUDED

#include <vector>
#include "engine.h"
#include "wing.h"

class Aircraft
{
public:
    double DOM;
    double MTOM;
    double MLM;
    double MTAXI;
    vector<Wing> wing;
};


#endif // AIRCRAFT_H_INCLUDED
