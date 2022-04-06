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
		Node(const Node *inst) : LeftNode(inst->LeftNode), RightNode(inst->RightNode), Parrent(inst->Parrent), Data(inst->Data) {}
		~Node() {}
};


#endif
