#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0)
            return false;
    return n != 1;
}

template <typename T>
void solve_VRUCHNUYU(const vector<int>& inp)
{
    T a(inp.begin(), inp.end());
    auto pos = a.begin();
    for(auto it = a.begin(); it != a.end(); ++it)
        if(is_prime(*it))
            iter_swap(pos++, it);
    for(auto it = a.begin(); it != a.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
}

template <typename T>
void solve_algoritmically(const vector<int>& inp)
{
    T a(inp.begin(), inp.end());
    remove_if(a.begin(), a.end(), not1(function<bool(int)>(is_prime)));
    for(auto it = a.begin(); it != a.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
}

    

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x : a)
        cin >> x;
    solve_VRUCHNUYU<vector<int>>(a);
    solve_VRUCHNUYU<list<int>>(a);
    solve_algoritmically<vector<int>>(a);
    solve_algoritmically<list<int>>(a);
}
    
