#include <iostream>
#include "Vector.hpp"
#include "Stack.hpp"
#include "utility.hpp"
#include "reverse_iterator.hpp"
#include <vector>
#include <deque>
#include <stack>
#define VIOLET "\033[1;35m"
#define DEFAULT "\033[0;37m"

void vector_tests()
{
	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

	std::cout <<VIOLET<< "\t\t\t\tV E C T O R\nconstructors/begin/end tests\n" <<DEFAULT;
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

	std::vector<int> vec1 (3,0);			ft::Vector<int> vec3 (3,0);
	std::vector<int> vec2 (5,0);			ft::Vector<int> vec4 (5,0);

	vec1 = vec2;							vec3 = vec4;
	vec2 = std::vector<int>();				vec4 = ft::Vector<int>();
	std::cout << "std::vector:\nSize of vec1: " << int(vec1.size()) << '\n';
	std::cout << "Size of vec2: " << int(vec2.size()) << '\n';
	std::cout << "ft::Vector:\nSize of vec3: " << int(vec3.size()) << '\n';
	std::cout << "Size of vec4: " << int(vec4.size()) << '\n';
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "\nempty/front/back/capacity tests\n" <<DEFAULT;
	std::vector<int> vec1;					ft::Vector<int> vec2;
	std::cout  << "std::vector:\nis vec1 Empty? " << std::boolalpha << vec1.empty() << '\n';
	std::cout << "ft::Vector:\nis vec2 Empty? " << std::boolalpha << vec2.empty() << '\n';
	vec1.push_back(111);					vec2.push_back(111);
	vec1.push_back(222);					vec2.push_back(222);
	std::cout << "std::vector:\nis vec1 Empty? " << std::boolalpha << vec1.empty() << '\n';
	std::cout << "ft::Vector:\nis vec2 Empty? " << vec2.empty() << '\n';
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

	myvector.insert (it+2,anothervec.end(),anothervec.begin());
		try
		{
		myvector1.insert (ft_it+2,anothervec.end(),anothervec.begin());
		}
		catch(const std::exception& e)
		{
		std::cerr << e.what() << '\n'; //Vector: Invalid iterator
		}

	std::cout << "std::vector contains: " << myvector[0] << " " <<  myvector[1]
		<< " " << myvector[2] << " " << myvector[3] << " " << myvector[4] <<
		"... size: " << myvector.size() << "\n";
	std::cout << "ft::Vector contains: " << myvector1[0] << " " <<  myvector1[1]
		<< " " << myvector1[2] << " " << myvector1[3] << " " << myvector1[4] <<
		"... size: " << myvector1.size() << "\n";

	myvector.insert (it+2,anothervec.begin(),anothervec.end());
	myvector1.insert (ft_it+2,anothervec.begin(),anothervec.end());

	std::cout << "std::vector contains: " << myvector[0] << " " <<  myvector[1]
		<< " " << myvector[2] << " " << myvector[3] << " " << myvector[4] <<
		"... size: " << myvector.size() << "\n";
	std::cout << "ft::Vector contains: " << myvector1[0] << " " <<  myvector1[1]
		<< " " << myvector1[2] << " " << myvector1[3] << " " << myvector1[4] <<
		"... size: " << myvector1.size() << "\n";
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "\nmax_size/reserve/resize tests\n" <<DEFAULT;
	std::vector<int> myvector (3,100);			ft::Vector<int> myvector1 (3,100);
	std::cout << "std::vector max_size: " << myvector.max_size() << "\n";
	std::cout << "ft::Vector max_size: " << myvector1.max_size() << "\n";
	std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
	std::cout << "ft::Vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
	myvector.reserve(10000);								myvector1.reserve(10000);
	std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
	std::cout << "ft::Vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
	myvector.resize(100);						myvector1.resize(100);
	myvector.resize(1);							myvector1.resize(1);
	std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
	std::cout << "ft::Vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
		std::cout <<VIOLET<< "\nat/operator >< = != tests\n" <<DEFAULT;
		std::vector<int> vec(5);				std::vector<int> vec1(10, 2);
		if (vec == vec1)
			std::cout << "std:: vec = vec1\n";
		if (vec != vec1)
			std::cout << "std:: vec != vec1\n";
		if (vec > vec1)
			std::cout << "std:: vec > vec1\n";
		if (vec < vec1)
			std::cout << "std:: vec < vec1\n";
		ft::Vector<int> vec2(1 , 20);			ft::Vector<int> vec3(3, 10);
		if (vec2 == vec3)
			std::cout << "ft:: vec2 = vec3\n";
		if (vec2 != vec3)
			std::cout << "ft:: vec2 != vec3\n";
		if (vec2 > vec3)
			std::cout << "ft:: vec2 > vec3\n";
		if (vec2 < vec3)
			std::cout << "ft:: vec2 < vec3\n";

		try
		{
			std::cout << "std::vector: ";
			std::cout << vec1.at(8) << "\n";
			std::cout << vec1.at(20) << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "ft::vector: ";
			std::cout << vec3.at(2) << "\n";
			std::cout << vec3.at(20) << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "\nerase/clear/assign/push_back/pop_back tests\n" <<DEFAULT;
	std::vector<int> myvector (3,100);			ft::Vector<int> myvector1 (3,100);
	std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
	std::cout << "ft::Vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
	myvector.erase(myvector.begin());			myvector1.erase(myvector1.begin());
	std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
	std::cout << "ft::Vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
	myvector.clear();							myvector1.clear();
	std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
	std::cout << "ft::Vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
	myvector.assign(5, 10);			myvector1.assign(5, 10);
	std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
	std::cout << "ft::Vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
	myvector.push_back(1);			myvector1.push_back(1);
	myvector.push_back(1);			myvector1.push_back(1);
	myvector.pop_back();			myvector1.pop_back();
	std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
	std::cout << "ft::Vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
}

void stack_tests()
{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "\n\t\t\t\tS T A C K\nconstructors/size/push/pop/operator >< = != tests\n" <<DEFAULT;
	std::stack<int> first;                    // empty stack
	ft::Stack<int> first1;


	std::cout << "std::stack:\nis first Empty? " << std::boolalpha <<first.empty() << std::endl;
	std::cout << "ft::Stack:\nis first1 Empty? "<< std::boolalpha <<first1.empty() << std::endl;
	first.push(1); first.push(2); first.push(3); first.push(4);
	first1.push(1); first1.push(2); first1.push(3); first1.push(4);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of first1: " << first1.size() << '\n';

	std::stack<int> second(first);		// stack initialized to copy of first
	ft::Stack<int> second1(first1);		//4 3 2 1

	std::cout << "top of second: " << second.top() << '\n';
	std::cout << "top of second1: " << second1.top() << '\n';

	second.pop(); //3 2 1
	second1.pop(); //3 2 1

	std::cout << "top of second: " << second.top() << '\n';
	std::cout << "top of second1: " << second1.top() << '\n';


	if (first == second)						//first/4 3 2 1  second/3 2 1
		std::cout << "std:: first = second\n";
	if (first != second)
		std::cout << "std:: first != second\n";
	if (first > second)
		std::cout << "std:: first > second\n";
	if (first < second)
		std::cout << "std:: first < second\n";

	if (first1 == second1)
		std::cout << "ft:: first1 = second1\n";
	if (first1 != second1)
		std::cout << "ft:: first1 != second1\n";
	if (first1 > second1)
		std::cout << "ft:: first1 > second1\n";
	if (first1 < second1)
		std::cout << "ft:: first1 < second1\n";

}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/


int main()
{
		vector_tests();
		stack_tests();

	// std::string n;
	// std::cout <<VIOLET<< "PRESS "<<DEFAULT<< "v"<<VIOLET<< " for testing vector\n";
	// std::cout << "      "<<DEFAULT<< "s"<<VIOLET<< " for testing stack\n";
	// std::cout << "      "<<DEFAULT<< "m"<<VIOLET<< " for testing map\n";
	// std::cout << "      "<<DEFAULT<< "set"<<VIOLET<< " for testing set\n"<<DEFAULT;
	// std::cin >> n;
	// 	std::string arr[4] = {"v", "s", "m", "set"};
	// int i = 0;
	// while (i < 4 && n != arr[i])
	// 	i++;
	// enum Level {v, s, m, set};
	// switch (i)
	// {
	// 	case v:
	// 		vector_tests();
	// 	case s:
	// 		// stack_tests();
	// 	case m:
	// 		// map_tests();
	// 	case set:
	// 		// set_tests();
	// 		break;
	// 	default:
	// 		// vector_tests();
	// 		// stack_tests();
	// 		// map_tests();
	// 		// set_tests();
	// }
}
