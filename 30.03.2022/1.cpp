#include <bits/stdc++.h>
using namespace std;

template <typename It>
void SelectionSort(It begin, It end)
{
    for(auto it = begin; it < end; ++it) {
        auto mn = it;
        for(auto jt = it; jt < end; ++jt)
            if(*jt < *mn) 
                mn = jt; 
        swap(*mn, *it);
    }
}

int main()
{
    vector<int> a{4, 2, 1, 5, 3, 3, 2, 1};
    SelectionSort(a.begin(), a.end());
    for(int& x : a)
        cout << x << ' ';
}
