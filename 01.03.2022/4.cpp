#include <iostream>

template<typename T>
T* createarray(int n)
{
	T* ptr = new T[n];
	for(int i = 0; i < n; ++i)
	{
		ptr[i] = i + 1;
	}
	return ptr;
}

int main()
{
	int *arr = createarray<int>(5);
	for(int i = 0; i < 5; ++i)
	{
		std::cout << arr[i] << ' ';
	}
}
