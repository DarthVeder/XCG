#include "engine.h"

double TurbofanEngine::Thrust(double h, double v)
{
	return TSL;
}

double TurbofanEngine::FuelFlow(double h, double v)
{
	return SFC*TSL;
}

void TurbofanEngine::setThrustPosition(vector<Point> engPoints)
{
	Point t_;
	for (int i=0; i<engPoints.size(); i++)
	{
		t_.x = engPoints[i].x;
		t_.y = engPoints[i].y;
		t_.z = engPoints[i].z;
		xT.push_back(t_);
	}
}


