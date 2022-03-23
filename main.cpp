#include <iostream>
#include "Vector.hpp"
#include "utility.hpp"
#include "reverse_iterator.hpp"
#include <vector>
#define VIOLET "\033[1;35m"
#define DEFAULT "\033[0;37m"

void vector_tests()
{
	{
	std::cout <<VIOLET<< "\t\t\t\tVECTOR\nconstructors/begin/end tests\n" <<DEFAULT;
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third

	ft::Vector<int> my_first;                                // empty vector of ints
	ft::Vector<int> my_second (4,100);                       // four ints with value 100
	ft::Vector<int> my_third (my_second.begin(),my_second.end());  // iterating through second
	ft::Vector<int> my_fourth (my_third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	ft::Vector<int> my_fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of std::vector are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of my::Vector are:";
	for (ft::Vector<int>::iterator my_it = my_fifth.begin(); my_it != my_fifth.end(); ++my_it)
		std::cout << ' ' << *my_it;
	std::cout << '\n';
	}

	{
	std::cout <<VIOLET<< "\nsize/operator= tests\n" <<DEFAULT;

	std::vector<int> vec1 (3,0);		ft::Vector<int> vec3 (3,0);
	std::vector<int> vec2 (5,0);		ft::Vector<int> vec4 (5,0);

	vec1 = vec2;						vec3 = vec4;
	vec2 = std::vector<int>();			vec4 = ft::Vector<int>();

	std::cout << "std::vector:\nSize of vec1: " << int(vec1.size()) << '\n';
	std::cout << "Size of vec2: " << int(vec2.size()) << '\n';

	std::cout << "ft::Vector:\nSize of vec3: " << int(vec3.size()) << '\n';
	std::cout << "Size of vec4: " << int(vec4.size()) << '\n';
	}
}



int main()
{
	vector_tests();
}
