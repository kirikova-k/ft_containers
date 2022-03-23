#include <iostream>

template <typename T>
typename T::type f(T x)
{
	std::cout << "1\n";
	return ((T)3);
}

template <typename ... >
int f(... )
{
	std::cout << "2\n";
	return (3);
}

int main()
{
	f(5);
	return 0;
}
