#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <vector>

using namespace std;

/*! \file engine.h
\brief Contains four possible engine power plants
*/

struct Point
{
	double x;
	double y;
	double z;
};


/*! \class Engine
Generic class, it does not need to be used.
*/
class Engine
{
    public:
        int number_of_engines;
		vector<Point> xT;
        virtual double Thrust(double h, double v) { return 0.0; } ;
        virtual double FuelFlow(double h, double v) { return 0.0; } ;
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
		void setThrustPosition(vector<Point> engPoints);
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



#endif // ENGINE_H_INCLUDED
