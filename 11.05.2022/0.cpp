#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(const T& a)
{
    for(auto& x : a)
        cout << x << ' ';
    cout << '\n';
}

template<size_t i>
void print_all() {};

template <size_t i = 1, typename Head, typename... Tail>
void print_all(Head& H, Tail&... T)
{
   cout << i << ": ";
   print(H);
   print_all<i + 1>(T...); 
}


int main()
{
    list<char> fork, deadend[2];
    string s;
    cin >> s;
    for(char& ch : s)
        fork.push_back(ch);
    int q;
    cin >> q;
    while(q--)
    {
        char ch; int p;
        cin >> ch >> p;
        auto pos = find(fork.begin(), fork.end(), ch);
        int cnt = 0;
        while(pos != prev(fork.end()))
        {
            int back = fork.back();
            deadend[!p].push_front(back);
            fork.pop_back();
            ++cnt;
        }
        deadend[p].push_front(*pos);
        fork.pop_back();
        print_all(fork, deadend[0], deadend[1]);
        for(int i = 0; i < cnt; ++i)
        {
            int num = deadend[!p].front();
            deadend[!p].pop_front();
            fork.push_back(num);
        }
        print_all(fork, deadend[0], deadend[1]);
    }
}
