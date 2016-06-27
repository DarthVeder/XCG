#ifndef AIRCRAFT_H_INCLUDED
#define AIRCRAFT_H_INCLUDED

#include <vector>
#include "engine.h"
#include "wing.h"


class Aircraft
{
public:
    ~Aircraft() { delete pengine; };
    Aircraft() { pengine = new Engine; };
    Engine *pengine;
    vector<Wing> wing;
    double reference_datum_position;
    double DOM;
    double MTOM;
    double MLM;
    double MTAXI;
};


#endif /* AIRCRAFT_H_INCLUDED */
