#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double c, angle;
    cout << "Enter the hypotenuse length: ";
    cin >> c;
    cout << "Enter the angle (in radians): ";
    cin >> angle;
    double a = sin(angle) * c;
    double b = cos(angle) * c;
    cout << "Perimeter: " << a + b + c << endl;
    cout << "Area: " << a*b/2;
}
