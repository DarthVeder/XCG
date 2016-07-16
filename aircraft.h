#ifndef AIRCRAFT_H_INCLUDED
#define AIRCRAFT_H_INCLUDED

#include <map>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

const double PI = asin(1.)*2.;

enum engine_t { Piston =0, Jet=1, None=2, HeloTurbine=3, Rocket=4, Turboprop=5};

class Aircraft
{
private:
    map< string, double > data;
public:
    Aircraft() {};
    // Insert method:
    void insertKeyValue(string key, double value) { data[key] = value; };

    // Output methods:
    void computeData();

    void print();
};


#endif /* AIRCRAFT_H_INCLUDED */
