#ifndef NODE_HPP

#include <iostream>
using namespace std;

class Node
{
	public:
		int Data;
		Node *LeftNode;
		Node *RightNode;
		Node *Parrent;

		Node() {Parrent = nullptr; LeftNode = nullptr; RightNode = nullptr; Data = 0;}
		Node(int data) {Parrent = nullptr; LeftNode = nullptr; RightNode = nullptr; Data = data;}
		~Node() {}
};


#endif
