#include "engine.h"

double TurbofanEngine::Thrust(double h, double v)
{
	return TSL;
}

double TurbofanEngine::FuelFlow(double h, double v)
{
	return SFC*TSL;
}



