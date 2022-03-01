#include <iostream>
using namespace std;

int N;

void line(int n, int character)
{
	if(n > 0)
	{
		cout << character;
		line(n - 1, character);
	}
	else if(n == 0)
	{
		cout << '\n';
	}
}

int f(int n, int character)
{
	if(n < N)
	{
		line(n + 1, character);
		f(n + 1, !character);
		if(n + 1 != N)
			line(n + 1, character);
	}
}

int rec(int n)
{
	f(0, 0);
}

int main()
{
	cin >> N;
	rec(N);
}
