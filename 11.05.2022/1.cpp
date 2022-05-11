#include <bits/stdc++.h>
using namespace std;

//transform provides additional output iterator argument
//meanwhile for_each do operations in-place

//example:

int main()
{
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> b = a;
    vector<int> output(b.size());
    auto doubled = [](int& a) { return a *= 2; };
    for_each(a.begin(), a.end(), doubled);
    transform(a.begin(), a.end(), output.begin(), doubled);
    for(int& x : a)
        cout << x << ' ';
    cout << endl;
    for(int& x : b)
        cout << x << ' ';
    cout << endl;
    for(int& x : output)
        cout << x << ' ';
}
