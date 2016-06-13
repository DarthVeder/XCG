#include "isa.h"

double ISA::ft2m(double hft_)
{
    double hm_;

    hm_ = hft_*0.3048;

    return hm_;
}

double ISA::m2ft(double hm_)
{
    double hft_;

    hft_ = hm_/0.3048;

    return hft_;
}

void ISA::print()
{
    cout<<setw(50)<<"       h(m)      h(ft)  p(Pa)         T(C)    rho(kg/m^3)   a(m/s)"<<endl;
    for (double h=0; h<=20e3; h+=1000)
    {
        cout<<setw(10)<<setprecision(0)<<fixed<<h<<" ";
        cout<<setw(10)<<fixed<<setprecision(0)<<m2ft(h)<<" ";
        cout<<setw(10)<<setprecision(2)<<pressure(h)<<" ";
        cout<<setw(10)<<setprecision(2)<<temperature(h)-273.15<<" ";
        cout<<setw(10)<<setprecision(2)<<density(h)<<" ";
        cout<<setw(10)<<setprecision(2)<<asound(h)<<endl;
    }
}

ISA::ISA()
{
    rhoSL = 1.225; // kg/m^3
    TSL = 288.15; // K
    pSL = 1013.25e2; // Pa
    Rair = 287.0528; // J/kgK
    gamma = 1.4; 
    g = 9.806645; // m/s^2
    dTdz = -6.5/1000; // K/m
}

double ISA::density(double h)
{
    double rho_, p_, T_;

    p_ = pressure(h);
    T_ = temperature(h);
    rho_ = p_/(Rair*T_);

    return rho_;
}

double ISA::temperature(double h)
{
    double T_ = 0.0;

    if (h<=11000)
    {
        T_ = TSL + dTdz*h;
    }
    else
    {
        T_ = TSL + dTdz*11e3;
    }

    return T_;
}


double ISA::pressure(double h)
{
    double p_ = 0.0;
    double T_ = temperature(h);

    if (h<=11000)
    {
        p_ = T_/TSL;
        p_ = pow(p_,-g/(Rair*dTdz));
        p_ = pSL * p_;
    }
    else
    {
        p_ = exp(-g*(h-11e3)/(Rair*216.65));
        p_ = 22632*p_;
    }

    return p_;
}

double ISA::asound(double h)
{
    double a_ = 0.0, T_ = 0.0;

    T_ = temperature(h);
    a_ = sqrt(gamma*Rair*T_);

    return a_;
}
