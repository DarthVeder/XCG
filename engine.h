#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <vector>

using namespace std;

/*! \file engine.h
\brief Contains four possible engine power plants
*/

/*! \class Engine
Generic class, it does not need to be used.
*/
class Engine
{
private:
    int m_number_of_engines;
    vector<double> m_xT;
public:
    virtual ~Engine() {} ;
    Engine() : m_number_of_engines(0)
    {
        m_xT.resize(3);
    };
    Engine(int nengs, vector<double> xT) : m_number_of_engines(nengs)
    {
        xT.resize(3);
        setEnginePosition(xT);
    };
    void setEnginePosition(vector<double> xT)
    {
        m_xT = xT;
    };
    vector<double> getEnginePosition()
    {
        return m_xT;
    };
    virtual double Thrust(double h, double v) { return 0.; };
    virtual double FuelFlow(double h, double v) { return 0.; };
};

class PistonEngine : public Engine
{
public:
    double PSL;
    double eta_p;
    double SFC;
};

class TurbofanEngine : public Engine
{
public:
    double TSL;
    double SFC;
    void setThrustPosition(vector<double> engPoints);
    double Thrust(double h, double v);
    double FuelFlow(double h, double v);
};

class TurbopropEngine : public Engine
{
public:
    double TSL;
    double PSL;
    double BSFC;
};



#endif /* ENGINE_H_INCLUDED */
