#include <iostream>
#include "Vector.hpp"
#include <vector>

int main()
{
	ft::Vector<int> a;
	std::vector<int> b;
	b.push_back(2);

	std::cout << a.back() << " \n";// << b.begin();
	return 0;
}
