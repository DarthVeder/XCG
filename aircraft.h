#ifndef AIRCRAFT_H_INCLUDED
#define AIRCRAFT_H_INCLUDED

#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Aircraft
{
private:
    map< string, double > data;
public:
    Aircraft() {};
    // Insert method:
    void insertKeyValue(string key, double value) { data[key] = value; };

    // Output methods:
    double aspectRatio();

    void print();
};


#endif /* AIRCRAFT_H_INCLUDED */
