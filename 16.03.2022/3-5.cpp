#include <stdexcept>
#include <algorithm>

struct triangle
{
    int a,b,c;

    static int cnt;

    triangle(int a, int b, int c)
    {
        int arr[3] = {a, b, c};
        std::sort(arr, arr + 3);
        this->a = a;
        this->b = b;
        this->c = c;
        if(!(a + b < c))
            throw std::invalid_argument("Not a triangle");
        if(a*a + b*b == c*c)
            ++cnt;
    }

    bool operator==(const triangle& rhs) const
    {
        return this->a == rhs.a && this->b == rhs.b && this->c == rhs.c;
    }
    
    bool operator!=(const triangle& rhs) const
    {
        return !(*this == rhs);
    }
};

int triangle::cnt = 0;
