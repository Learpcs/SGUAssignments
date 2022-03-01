#include <iostream>
#include <cmath>

struct point
{
	int x,y;
	virtual double  distance() const
	{
		return sqrt(x*x + y*y);
	}
}

struct point3d : public pointer
{
	int z;
	double distance() const
	{
		return sqrt(x*x + y*y + z*z);
	}
}

double distance(point)
