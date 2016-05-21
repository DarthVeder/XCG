#ifndef ISA_H_INCLUDED
#define ISA_H_INCLUDED

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class ISA
{
private:
    double rhoSL;
    double TSL;
    double pSL;
    double Rair;
    double gamma;
    double g;
    double dTdz;
public:
    ISA();
    double pressure(double h); // h in m
    double temperature(double h);
    double density(double h);
    double asound(double h);
    void print();
    double ft2m(double hft);
    double m2ft(double hm);
};


#endif // ISA_H_INCLUDED
