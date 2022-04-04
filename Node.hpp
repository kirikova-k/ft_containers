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

		Node() {Parrent = NULL; LeftNode = NULL; RightNode = NULL; Data = 0;}
		Node(int data) {Parrent = NULL; LeftNode = NULL; RightNode = NULL; Data = data;}
		~Node() {}
};


#endif
