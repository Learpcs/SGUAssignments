#include <tuple>

struct ball
{
     std::tuple<int,int,int> color;
     double weight;

    ball(const ball& rhs)
    {
        this->color = rhs.color;
        this->weight = rhs.weight;
    }

     bool operator<(const ball& rhs) const
     {
         return this->weight < rhs.weight;
     }

     bool operator==(const ball& rhs) const
     {
         return this->weight == rhs.weight && this->color == rhs.color;
     }

     ball& operator=(const ball& rhs)
     {
         this->color = rhs.color;
         this->weight = rhs.weight;
         return *this;
     }
}
