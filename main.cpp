#include <iostream>
#include "Vector.hpp"
#include "utility.hpp"
#include "reverse_iterator.hpp"
#include <vector>
#define VIOLET "\033[1;35m"
#define DEFAULT "\033[0;37m"

void vector_tests()
{
	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

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
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "\nsize/operator= tests\n" <<DEFAULT;

	std::vector<int> vec1 (3,0);		ft::Vector<int> vec3 (3,0);
	std::vector<int> vec2 (5,0);		ft::Vector<int> vec4 (5,0);

	vec1 = vec2;						vec3 = vec4;
	vec2 = std::vector<int>();			vec4 = ft::Vector<int>();
	std::cout << "std::vector:\nSize of vec1: " << int(vec1.size()) << '\n';
	std::cout << "Size of vec2: " << int(vec2.size()) << '\n';
	std::cout << "ft::Vector:\nSize of vec3: " << int(vec3.size()) << '\n';
	std::cout << "Size of vec4: " << int(vec4.size()) << '\n';
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "\nempty/front/back/capacity tests\n" <<DEFAULT;
	std::vector<int> vec1;				ft::Vector<int> vec2;

	std::cout << "std::vector:\nis vec1 Empty? " << int(vec1.empty()) << '\n';
	std::cout << "ft::Vector:\nis vec2 Empty? " << int(vec2.empty()) << '\n';
	vec1.push_back(111);	vec2.push_back(111);
	vec1.push_back(222);	vec2.push_back(222);
	std::cout << "std::vector:\nis vec1 Empty? " << int(vec1.empty()) << '\n';
	std::cout << "ft::Vector:\nis vec2 Empty? " << int(vec2.empty()) << '\n';
	std::cout << "std::vector:\ncapacity of vec1: " << int(vec1.capacity()) << '\n';
	std::cout << "ft::Vector:\ncapacity of vec2: " << int(vec2.capacity()) << '\n';
	std::cout << "std::vector:\nfirst of vec1: " << int(vec1.front()) << '\n';
	std::cout << "ft::Vector:\nfirst of vec2: " << int(vec2.front()) << '\n';
	std::cout << "std::vector:\nlast of vec1: " << int(vec1.back()) << '\n';
	std::cout << "ft::Vector:\nlast of vec2: " << int(vec2.back()) << '\n';
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "\ninsert/operator[] tests\n" <<DEFAULT;

	std::vector<int> myvector (3,100);		ft::Vector<int> myvector1 (3,100);
	std::vector<int>::iterator it;			ft::Vector<int>::iterator ft_it;
	it = myvector.begin();					ft_it = myvector1.begin();
	it = myvector.insert ( it , 2 );		ft_it = myvector1.insert ( ft_it , 2 );

	std::cout << "std::vector contains: " << myvector.front() << " " <<
		myvector.back() << " size: " << myvector.size() << "\n";
	std::cout << "ft::Vector contains: " << myvector1.front() << " " <<
		myvector1.back() << " size: " << myvector1.size() << "\n";

	myvector.insert (it,2,300);				myvector1.insert (ft_it,2,300);

	std::cout << "std::vector contains: " << myvector.front() << " " <<
		myvector.back() << " size: " << myvector.size() << "\n";
	std::cout << "ft::Vector contains: " << myvector1.front() << " " <<
		myvector1.back() << " size: " << myvector1.size() << "\n";

	// "it" no longer valid, get a new one:
	it = myvector.begin();					ft_it = myvector1.begin();

	std::vector<int> anothervec(2,400);

	myvector.insert (it+2,anothervec.begin(),anothervec.end());
	myvector1.insert (ft_it+2,anothervec.begin(),anothervec.end());

	std::cout << "std::vector contains: " << myvector[0] << " " <<  myvector[1]
		<< " " << myvector[2] << " " << myvector[3] << " " << myvector[4] <<
		"... size: " << myvector.size() << "\n";
	std::cout << "ft::Vector contains: " << myvector1[0] << " " <<  myvector1[1]
		<< " " << myvector1[2] << " " << myvector1[3] << " " << myvector1[4] <<
		"... size: " << myvector1.size() << "\n";

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/


}



int main()
{
	vector_tests();
}
