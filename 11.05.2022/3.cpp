#include <bits/stdc++.h>
using namespace std;

template<typename T>
void solve_algorithmically(vector<int> arr, int pos)
{
    T a(arr.begin(), arr.end());
    rotate(a.begin(), next(a.begin(), pos), a.end());
    for(int& x : a)
        cout << x << ' ';
    cout << '\n';
}

template <typename T>
void solve_samomu(vector<int> arr, int pos)
{
    T a(arr.begin(), arr.end());
    reverse(a.begin(), a.end());
    auto it = next(a.begin(), pos + 1);
    reverse(a.begin(), it);
    reverse(++it, a.end()); 
    for(int& x : a)
        cout << x << ' ';
    cout << '\n';
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x : a)
        cin >> x;
    int pos;
    cin >> pos;
    solve_algorithmically<vector<int>>(a, pos);
    solve_algorithmically<list<int>>(a, pos);
    solve_samomu<vector<int>>(a, pos);
    solve_samomu<list<int>>(a, pos);
}
