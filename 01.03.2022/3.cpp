#include <iostream>
#include <cmath>

struct point
{
	double x,y;
	point()
	{}
	point(double X, double Y) : x(X), y(Y)
	{} 
	virtual double distance(const point& p1) const
	{
		return sqrt((p1.x - x) * (p1.x - x) + (p1.y - y)*(p1.y - y));
	}
};

struct point3d : public point
{
	double z;
	point3d(double X, double Y, double Z) 
	{
		this->x = X;
		this->y = Y;
		this->z = Z;
	}
	double distance(const point3d& p1) const
	{
		return sqrt((p1.x - x) * (p1.x - x) + (p1.y - y)*(p1.y - y) + (p1.z - z)* (p1.z - z));
	}
};

double distance(const point& p1, const point& p2)
{
	return p1.distance(p2);
}

double distance(const point3d& p1, const point3d& p2)
{
	return p1.distance(p2);
}

double distance(double x1, double y1, double x2, double y2)
{
	return point(x1, y1).distance({x2, y2});
}

double distance(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return point3d(x1, y1, z1).distance({x2,y2,z2});
}


int main()
{
	point3d a{0, 0, 0}, b{1 , 1, 1};
	std::cout << distance(a, b);
}
