#include <iostream>
#include <cmath>
using namespace std;

struct point
{
    double x;
    double y;

    point() 
    {
        cin >> x >> y;
    }
};

struct circle : public point
{
    double radius;

    circle()
    {
        cin >> radius;
    }
};

double distance(const circle& circ, const point& pt)
{
    return abs(circ.radius - sqrt((circ.x - pt.x) * (circ.x - pt.x) + (circ.y - pt.y) * (circ.y - pt.y)));
}


int main()
{
    //forgive my poor english grammar. 
    cout << "Enter the coordinates of the point (x, y): ";
    point pt;
    cout << "Enter the coordinates of the centre point of the circle and the radius (x, y, R): ";
    circle circ;
    cout << "Distance from point to circle: " << distance(circ, pt);

}
