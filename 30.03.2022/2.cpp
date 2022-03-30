#include <bits/stdc++.h>
using namespace std;

bool operator<(const string& lhs, const string& rhs)
{
    if(lhs.size() < rhs.size())
        return true;
    return false;
}

int main()
{
    string a = "abc", b = "abcd";
    cout << (a < b);
}

