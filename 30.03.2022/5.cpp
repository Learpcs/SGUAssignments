#include <iostream>
using namespace std;

class BBall
{
    int w;
    string color;
    int num;
public:

    static int n;

    BBall()  // = default
    {
        w = 1;
        color = "white";
        num = n;
        n++;
    }
    
    //BBall(int w, string color) : w(w), color(color) {}
    BBall(int w, string color)
    {
        setW(w);
        setColor(color);
        num = n;
        n++;
    }
    
    // BBall(const BBall & other) = delete;
    BBall(const BBall & other)
    {
        w = other.w;
        color = other.color;
        num = n;
        n++;
    }
        

    bool setW(int w)
    {
        if (w > 0)
        {
            this->w = w;  // (*this).w = w;
            return true;
        }
        return false;
    }
    
    bool setColor(string color)
    {
        if (color != "")
        {
            this->color = color;
            return true;
        }
        return false;
    }
    
    int getW()
    {
        return w;
    }

    int getNum()
    {
        return num;
    }
    
    string getColor()
    {
        return color;
    }
    
    ~BBall()
    {
        n--;
        cout << "Deleted ball "<< this->color << endl;
    }
        
    
    BBall& operator++()
    {
        w++;
        return *this;
    }
    
    BBall operator++(int)
    {
        BBall tmp = *this;
        w++;
        return tmp;
    }
    
    friend BBall operator+(BBall &ball, int x)
    {
        return BBall(ball.w + x, ball.color);
    }  
    friend BBall operator+(int x, BBall &ball)
    {
        return ball + x;
    } 
};

bool isLower(BBall *x, BBall *y)
{
  if (x->getW() != y->getW())
    return x->getW() < y->getW();
  return x->getNum() < y->getNum();
}

template <typename T>
void selectionSort(T *a, int n)
{
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (isLower(a[j], a[i]))
        swap(a[i], a[j]);  
}

template <typename T>
void insertionSort(T *a, int n)
{
  for (int i = 1; i < n; i++)
    for (int j = i; j > 0 && isLower(a[j], a[j - 1]); j--)
      swap(a[j - 1], a[j]);
}

template <typename T, typename Cmp>
void insertionSort(T *a, int n, Cmp cmp)
{
  for (int i = 1; i < n; i++)
    for (int j = i; j > 0 && cmp(a[j], a[j - 1]); j--)
      swap(a[j - 1], a[j]);
}
int BBall::n = 0;

int main() {
  int n;
  cin >> n;

  /*
  int *a = new int[n];
  int *b = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
     b[i] = a[i];
  }
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  cout << endl;
  insertionSort(a, n);    
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  cout << endl;
  selectionSort(b, n);
  for (int i = 0; i < n; i++)
    cout << b[i] << ' ';
  cout << endl;
  */
  
  BBall **balls = new BBall*[n];
for (int i = 0; i < n; i++)
  {
    int w;
    string color;
    cin >> w >> color;
    balls[i] = new BBall(w, color);
  }

  cout << endl;
  for (int i = 0; i < n; i++)
  {
    cout << balls[i]->getW() << ' ' << balls[i]->getColor() << ' ' << balls[i]->getNum();
    cout << endl;
  } 
  // insertionSort(balls, n);
  selectionSort(balls, n);

  cout << endl;
  for (int i = 0; i < n; i++)
  {
    cout << balls[i]->getW() << ' ' << balls[i]->getColor() << ' ' << balls[i]->getNum();
    cout << endl;
  } 
}
