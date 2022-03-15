#include <tuple>
#include <stdexcept>

struct triangle
{
    std::tuple<int, int, int> sides;

    triangle(int a, int b, int c)
    {
        int& A = std::get<0>(sides);
        int& B = std::get<1>(sides);
        int& C = std::get<2>(sides);
        A = a;
        B = b;
        C = c;
        if(!(a + b < c && a + c < b && b + c < a))
            throw std::invalid_argument("Not a triangle");
    }
};
