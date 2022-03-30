#include <bits/stdc++.h>
using namespace std;

bool operator<(const string& lhs, const string& rhs)
{
    if(lhs.size() < rhs.size())
        return true;
    else if(lhs.size() == rhs.size())
       for(int i = 0; i < lhs.size(); ++i) 
           if(lhs[i] != rhs[i])
               return lhs[i] < rhs[i];
    return false;
}

int main()
{
    string a = "abcd", b = "abce";
    cout << (a < b);
}


