#ifndef AIRCRAFT_H_INCLUDED
#define AIRCRAFT_H_INCLUDED

#include <vector>
#include "engine.h"
#include "wing.h"

class Mass
{
public:
    double DOM;
    double xCG_DOM;
    double MTOM;
    double MLM;
    double MTAXI;
};

class Aircraft
{
public:
    Engine engine;
    vector<Wing> wing;
    double reference_datum_position;
    Mass mass;

    void print();
};


#endif /* AIRCRAFT_H_INCLUDED */
