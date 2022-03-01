#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

int funny_function(int l, int r)
{
	if(r - l == 1)
		return a[l];
	else
	{
		int m = (l + r)/2;
		return funny_function(l, m) * funny_function(m, r);
	}
}

int main()
{
	int n;
	cin >> n;
	int inp;
	for(int i = 0; i < n; ++i)
	{
		cin >> inp;
		a.push_back(inp);
	}
	cout << funny_function(0, n);
}
