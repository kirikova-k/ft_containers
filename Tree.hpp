#ifndef TREE_HPP
#include <iostream>
#include "Node.hpp"

class Tree
{
private:
	Node *root;
	int tree_size;
	void print_tree(Node *curr)
	{
		if (curr)
		{
			print_tree(curr->LeftNode);
			std::cout << curr->Data << " ";
			print_tree(curr->RightNode);
		}
	}

	void delete_tree(Node *curr)
	{
		if (curr)
		{
			delete_tree(curr->LeftNode);
			delete_tree(curr->RightNode);
			delete curr;
		}
	}

 public:
	Tree(int key)
	{
		root = new Node(key);
		tree_size = 1;
	}

	~Tree() {delete_tree(root);}

	void print() {print_tree(root); std::cout << std::endl;}
	bool find(int key)
	{
		Node *curr = root;
		while (curr && curr->Data != key)
		{
			if (curr->Data > key)
				curr = curr->LeftNode;
			else
				curr = curr->RightNode;
		}
		return curr != NULL;
	}

	void insert(int key)
	{
		// ...  //
	}

	void erase(int);
	int size();
};

#endif
