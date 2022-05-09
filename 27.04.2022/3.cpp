#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x;
	cin >> n;
	queue<int> a;
	stack<int> b;
	for (size_t i = 0; i < n; i++)
    {
		cin >> x;
		a.push(x);
		b.push(x);
	}
	while (!a.empty()) 
    {
		x = a.front();
		a.pop();
		if (x % 2 == 0) 
			cout << x << ' ';
	}
	cout << '\n';
	while (!b.empty())
    {
		x = b.top();
		b.pop();
		if (x % 2 != 0) 
			cout << x << ' ';
	}
}

