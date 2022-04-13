#include <iostream>
#include "Vector.hpp"
#include "Stack.hpp"
#include "Map.hpp"
#include "Set.hpp"
#include "utility.hpp"
#include "reverse_iterator.hpp"
#include <vector>
#include <deque>
#include <map>
#include <set>
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

void map_tests()
{
	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "\n\t\t\t\tM A P\nconstructors/size/maxsize/empty/lower_bound/upper_bound tests\n" <<DEFAULT;
	std::map<char,int> first;		ft::Map<char,int> first1;
	first['a']=10;					first1['a']=10;
	first['b']=30;					first1['b']=30;
	first['c']=50;					first1['c']=50;
	first['d']=70;					first1['d']=70;
	first['f']=90;					first1['f']=90;
	//begin/end
	std::cout << "std::map<char,int> first: " << first.begin()->first << " " << first.begin()->second << std::endl;
	std::cout << "ft::map<char,int> first1: " << first1.begin()->first << " " << first1.begin()->second << std::endl;
	//range contructor
	std::map<char,int> second (first.begin(),first.end());
	ft::Map<char,int> second1 (first1.begin(),first1.end());
	//size/maxsize/empty
	std::cout << "std::map<char,int> second: " << second.size() << " " << second.max_size() << " " << std::boolalpha << second.empty() << std::endl;
	std::cout << "ft::map<char,int> second1: " << second1.size() << " " << second1.max_size() << " " << std::boolalpha << second1.empty() << std::endl;
	//copy contructor
	std::map<char,int> third (second);
	ft::Map<char,int> third1 (second1);
	// lower_bound/upper_bound
	std::cout << "std::map<char,int> first: " << third.lower_bound('e')->second << " " << third.upper_bound('b')->second << std::endl;
	std::cout << "ft::map<char,int> first1: " << third1.lower_bound('e')->second << " " << third1.upper_bound('b')->second << std::endl;
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "operator[]/at/pair/insert/swap tests\n" <<DEFAULT;
	std::map<float,std::string> first;		ft::Map<float,std::string> first1;
	first[0.1]="You ";						first1[0.1]="much ";
	first[0.2]="have ";						first1[0.2]="I ";
	first[0.3]="no ";						first1[0.3]="hate ";
	first[0.4]="idea ";						first1[0.4]="the ";
	first[0.5]="how ";						first1[0.5]="ft_containers ";
	//[]
	std::cout << "std::map<float,std::string> first: " << first[0.1] << first[0.2] << first[0.3]<< first[0.4] << first[0.5] << first[42] << std::endl;
	std::cout << "ft::map<float,std::string> first1: " << first1[0.1] << first1[0.2] << first1[0.3]<< first1[0.4] << first1[0.5] << first[42] << std::endl;
	//at
	try
	{
		std::cout << "std::map<float,std::string> first: " << first.at(0.5) << std::endl << first.at(0.6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "ft::map<float,std::string> first1: " << first1.at(0.5) << std::endl << first1.at(0.6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//pair/insert
	first.insert(std::pair<float, std::string>(99.9, "hello!"));
	first1.insert(ft::pair<float, std::string>(99.9, "hello!"));
	std::cout << "std::map<float,std::string> first: " << first[99.9] << std::endl;
	std::cout << "ft::map<float,std::string> first1: " << first1[99.9] << std::endl;
	//swap
	std::map<float,std::string> second;		ft::Map<float,std::string> second1;
	second[1]="one ";						second1[1]="one ";
	second[2]="two ";						second1[2]="two ";
	second[3]="three ";						second1[3]="three ";
	second[4]="four ";						second1[4]="four ";
	second[5]="five ";						second1[5]="five ";
	first.swap(second);
	first1.swap(second1);
	std::cout << "std::map: after swap first-second: " << first[1] << first[2] << second[0.1]<< second[0.2] << std::endl;
	std::cout << "ft::map: after swap first-second: " << first1[1] << first1[2] << second1[0.1]<< second1[0.2] << std::endl;

	//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "operator >< = !=/erase/count tests\n" <<DEFAULT;
	if (first == second)
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
	//erase
	std::cout << "first element of std::map before erase 1: "<< first.begin()->first << std::endl;
	std::cout << "first element of ft::map before erase 1: "<< first1.begin()->first << std::endl;
	first.erase(first.begin());
	first1.erase(first1.begin());
	std::cout << "first element of std::map after erase 1: " << first.begin()->first << std::endl;
	std::cout << "first element of ft::map after erase 1: " << first1.begin()->first << std::endl;

	//cout
	std::cout << "first.count(2): " << first.count(2) << std::endl;
	std::cout << "first1.count(2): " << first1.count(2) << std::endl;
	std::cout << "first.count(35): " << first.count(35) << std::endl;
	std::cout << "first1.count(35): " << first1.count(35) << std::endl;
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
}

void set_tests()
{
	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "\n\t\t\t\tS E T \nconstructors/insert/size/maxsize/empty/begin/empty tests\n" <<DEFAULT;
	std::set<int> first;                                // empty set of ints
	first.insert(0); first.insert(1); first.insert(2); first.insert(3);
	std::set<int> second (first.begin(), first.end());  // iterating through first
	std::set<int> third (second);                       // a copy of third

	ft::Set<int> first1;                                // empty vector of ints
	first1.insert(0); first1.insert(1); first1.insert(2); first1.insert(3);
	std::set<int> second1 (first1.begin(), first1.end());  // iterating through first
	std::set<int> third1 (second1);                       // a copy of third
	//Size/maxsize
	std::cout << "std::Set: Size/maxsize of first: " << first.size() << " " << first.max_size() << '\n';
	std::cout << "ft::Set: Size/maxsize of first1: " << first1.size() << " " << first1.max_size() << '\n';
	//empty
	std::cout << "std::Set: second is empty? : " << std::boolalpha << second.empty() << std::endl;
	std::cout << "ft::Set: second1 is empty? : " << std::boolalpha << second1.empty() << std::endl;
	//insert duplicate
	first1.insert(0);									first.insert(0);
	std::cout << "std::Set: Size/maxsize of first: " << first.size() << "\n";
	std::cout << "ft::Set: Size/maxsize of first1: " << first1.size() << '\n';
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::cout <<VIOLET<< "swap/find/cout tests\n" <<DEFAULT;
	std::set<int> first;								ft::Set<int> first1;
	first.insert(0); first.insert(1); first.insert(2); first.insert(3);
	first1.insert(0); first1.insert(1); first1.insert(2); first1.insert(3);
	std::set<int> second;								ft::Set<int> second1;
	second.insert(4); second.insert(5); second.insert(6); second.insert(7);
	second1.insert(4); second1.insert(5); second1.insert(6); second1.insert(7);
	std::cout << "std::set: before swap first-second: " << *(first.find(0)) << " " << *(first.find(1)) << " " << *(first.find(2)) << " " << *(first.find(3)) << std::endl;
	std::cout << "ft::set: before swap first-second: " << *(first1.find(0)) << " " << *(first1.find(1)) << " " << *(first1.find(2)) << " " << *(first1.find(3)) << std::endl;
	first.swap(second);
	first1.swap(second1);
	std::cout << "std::set: after swap first-second: " << *(first.find(4)) << " " << *(first.find(5)) << " " << *(first.find(6)) << " " << *(first.find(7)) << std::endl;
	std::cout << "ft::set: after swap first-second: " << *(first1.find(4)) << " " << *(first1.find(5)) << " " << *(first1.find(6)) << " " << *(first1.find(7)) << std::endl;
	//cout
	std::cout << "first.count(4): " << first.count(4) << std::endl;
	std::cout << "first1.count(4): " << first1.count(4) << std::endl;
	std::cout << "first.count(35): " << first.count(35) << std::endl;
	std::cout << "first1.count(35): " << first1.count(35) << std::endl;
	// lower_bound/upper_bound
	std::cout << "std::set: first: " << *(first.lower_bound(42)) << " " << *(first.upper_bound(1)) << std::endl;
	std::cout << "ft::set: first1: " << *(first1.lower_bound(42)) << " " << *(first1.upper_bound(1)) << std::endl;

	std::cout <<VIOLET<< "operator >< = !=/erase/count tests\n" <<DEFAULT;
	if (first == second)
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
}

int main()
{
	stack_tests();
	vector_tests();
	map_tests();
	set_tests();
	return 0;
}
