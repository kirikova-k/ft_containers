#ifndef NODE_HPP

#include <iostream>
using namespace std;
typedef enum { BLACK, RED } nodeColor;

class Node
{
	public:
		int Data;
		Node *LeftNode;
		Node *RightNode;
		Node *Parrent;
		nodeColor color;

		// Node() {Parrent = NULL; LeftNode = NULL; RightNode = NULL; Data = 0;}
		Node() {Parrent = NULL; LeftNode = NULL; RightNode = NULL; Data = 0; color = BLACK;}
		Node(int data) {Parrent = NULL; LeftNode = NULL; RightNode = NULL; Data = data;}
		// Node(const Node *inst) : LeftNode(inst->LeftNode), RightNode(inst->RightNode),
			// Parrent(inst->Parrent), Data(inst->Data) {}
		Node(const Node *inst) : LeftNode(inst->LeftNode), RightNode(inst->RightNode),
			Parrent(inst->Parrent), Data(inst->Data), color(inst->color) {}
		~Node() {}
};



#endif
