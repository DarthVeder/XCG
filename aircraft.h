#ifndef AIRCRAFT_H_INCLUDED
#define AIRCRAFT_H_INCLUDED

#include "engine.h"

class Aircraft
{
    public:
        Engine engine;
        double CD0;
        double k;
        double DCDf;
        double DCLf;
};


#endif // AIRCRAFT_H_INCLUDED
