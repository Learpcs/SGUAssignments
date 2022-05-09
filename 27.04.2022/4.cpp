#include <bits/stdc++.h>
using namespace std;

void first(vector<int> a)
{
    a.insert(a.begin() + 1, *min_element(a.begin(), a.end()));
    for(int& x : a)
        cout << x << ' ';
    cout << endl;
}

void second(const vector<int>& a)
{
    list<int> lst;
    for(const int& x : a)
        lst.push_back(x);
    lst.insert(++lst.begin(), *min_element(lst.begin(), lst.end()));
    for(int& x : lst)
        cout << x << ' ';
    cout << endl;
}

void third(const vector<int>& a)
{
    stack<int> s1, s2;
    for(const int& x : a)
        s1.push(x);
    int mn = s1.top();
    while(s1.size() != 1)
    {
        int x = s1.top();
        mn = min(mn, x);
        s1.pop();
        s2.push(x);
    }

    s2.push(mn);
    s2.push(s1.top());
    s1.pop();
    while(!s2.empty())
    {
        cout << s2.top() << ' ';
        s2.pop();
    }
    cout << endl;
}
    
void fourth(const vector<int>& a)
{
    queue<int> q1, q2;
    for(const int& x : a)
        q1.push(x);
    int mn = q1.front();
    while(!q1.empty())
    {
        int x = q1.front();
        mn = min(mn, x);
        q2.push(x);
        q1.pop();
    }
    q1.push(q2.front());
    q2.pop();
    q1.push(mn);
    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    while(!q1.empty())
    {
        cout << q1.front() << ' ';
        q1.pop();
    }
    cout << endl;
}


int main() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x : a)
        cin >> x;
    first(a);
    second(a);
    third(a);
    fourth(a);
}

