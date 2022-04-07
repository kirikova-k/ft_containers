#ifndef TREE_HPP
#include <iostream>
#include "Node.hpp"


int tabs = 0;

class Tree
{
private:
	Node *root;
	int tree_size;
	void print_tree(Node *curr)
	{
		if (curr != nil)
		{
			print_tree(curr->LeftNode);
			std::cout << curr->Data << " ";
			print_tree(curr->RightNode);
		}
	}

	void print_ltree(Node *curr)
	{
		if (curr == nil) return;
		tabs +=5;
		print_ltree(curr->LeftNode);
		for (int i = 0; i < tabs; i++) std::cout << " ";
		std::cout << curr->Data;
		if (curr != root)
			std::cout << '(' << curr->Parrent->Data << ')';
		std::cout << std::endl;
		print_ltree(curr->RightNode);
		tabs -=5;
		return;
	}

	void delete_tree(Node *curr)
	{
		if (curr != nil)
		{
			delete_tree(curr->LeftNode);
			delete_tree(curr->RightNode);
			delete curr;
		}
	}

public:
	Node *nil;
	Tree()
	{
		nil = new Node();
		root = nil;
		tree_size = 0;
	}

	Tree(int key)
	{
		nil = new Node();
		root = new Node(key);
		tree_size = 1;
	}

	~Tree() {delete_tree(root); delete nil;}

	Node *getRoot() {return root;}

	void inorder_print() {print_tree(root); std::cout << std::endl;}
	void print_like_tree()
	{
		print_ltree(root);
		std::cout << "_______________________________" << std::endl;
	}

	bool find(int key)
	{
		Node *curr = root;
		while (curr != nil && curr->Data != key)
		{
			if (curr->Data > key)
				curr = curr->LeftNode;
			else
				curr = curr->RightNode;
		}
		return curr != nil;
	}

	Node *find_node(int key)
	{
		Node *curr = root;
		while (curr && curr->Data != key)
		{
			if (curr->Data > key)
				curr = curr->LeftNode;
			else
				curr = curr->RightNode;
		}
			return curr == nil ? curr : NULL;///or nil?!
	}

	void insert(int key)
	{
		if (root == nil)
		{
			// delete root;////////
			root = new Node(key);
			root->Parrent = nil;
			root->LeftNode = nil;
			root->RightNode = nil;
			tree_size = 1;
			return;
		}
		Node *curr = root;
		while (curr != nil && curr->Data != key)
		{
			if (curr->Data > key && curr->LeftNode == nil)
			{
				curr->LeftNode = new Node(key);
				curr->LeftNode->Parrent = curr;
				curr->LeftNode->LeftNode = nil;
				curr->LeftNode->RightNode = nil;
				++tree_size;
				return;
			}
			if (curr->Data < key && curr->RightNode == nil)
			{
				curr->RightNode = new Node(key);
				curr->RightNode->Parrent = curr;
				curr->RightNode->LeftNode = nil;
				curr->RightNode->RightNode = nil;
				++tree_size;
				return;
			}
			if (curr->Data > key)
				curr = curr->LeftNode;
			else
				curr = curr->RightNode;
		}
	}

	void erase(int key)
	{
		Node *curr = root;
		Node *parent_tmp = nil;
		while (curr != nil && curr->Data != key)
		{
			parent_tmp = curr;//
			if (curr->Data > key)
				curr = curr->LeftNode;
			else
				curr = curr->RightNode;
		}
		if (curr == nil)
			return;
		if (curr->LeftNode == nil && curr->RightNode == nil)
		{// case 1: no child
			if (curr == root)
			{
				root = nil;
				tree_size = 0;
				return;
			}
			if (curr == curr->Parrent->LeftNode)
				curr->Parrent->LeftNode = nil;
			else
				curr->Parrent->RightNode = nil;
		}
		else if (curr->LeftNode == nil) //case 2: left child
		{//вместо curr подвешивается его правое поддерево
			if (curr == root)
			{
				curr->RightNode->Parrent = nil;
				root = curr->RightNode;
			}
			if (parent_tmp != nil && parent_tmp->LeftNode == curr)
				parent_tmp->LeftNode = curr->RightNode;
			if (parent_tmp != nil && parent_tmp->RightNode == curr)
				parent_tmp->RightNode = curr->RightNode;
			curr->RightNode->Parrent = parent_tmp;
		}
		else if (curr->RightNode == nil)//case 3: right child
		{//вместо curr подвешивается его левое поддерево
			if (curr == root)
			{
				curr->LeftNode->Parrent = nil;
				root = curr->LeftNode;
			}
			if (parent_tmp != nil && parent_tmp->LeftNode == curr)
				parent_tmp->LeftNode = curr->LeftNode;
			if (parent_tmp != nil && parent_tmp->RightNode == curr)
				parent_tmp->RightNode = curr->LeftNode;
			curr->LeftNode->Parrent = parent_tmp;
		}
		else if (curr->LeftNode != nil && curr->RightNode != nil)
		{//case 4: 2 child
		//У элемента есть два потомка, тогда на место элемента поставим
		//наименьший элемент из его правого поддерева
		Node *replace = this->succesor(curr);
		Node *replace_copy = new Node(replace);
		erase(replace->Data);
		replace_copy->LeftNode = curr->LeftNode;
		replace_copy->RightNode = curr->RightNode;
		if (curr->Parrent != nil)
			replace_copy->Parrent = curr->Parrent;
		if (parent_tmp && parent_tmp != nil && parent_tmp->LeftNode == curr) //parent_tmp && parent_tmp != nil?
			parent_tmp->LeftNode = replace_copy;
		if (parent_tmp && parent_tmp != nil && parent_tmp->RightNode == curr)//parent_tmp && parent_tmp != nil?
			parent_tmp->RightNode = replace_copy;
		if (curr->LeftNode != nil)
			curr->LeftNode->Parrent = replace_copy;
		if (curr->RightNode != nil)
				curr->RightNode->Parrent = replace_copy;
		if (curr == root)
			root = replace_copy;
		}
		delete curr;
		tree_size--;
		return;
	}

	int size() {return tree_size;}

	Node *tree_max(Node *curr)
	{
		while (curr->RightNode != nil)
			curr = curr->RightNode;
		return curr;
	}

	Node *tree_min(Node *curr)
	{
		while (curr->LeftNode != nil)
			curr = curr->LeftNode;
		return curr;
	}

	Node *succesor(Node *curr)
	{
		if (curr->RightNode != nil)
			return (this->tree_min(curr->RightNode));
		Node *tmp = curr->Parrent;
		while (tmp != nil && curr == tmp->RightNode)
		{
			curr = tmp;
			tmp = tmp->Parrent;
		}
		return tmp;
	}

		Node *predecesor(Node *curr)
	{
		if (curr->LeftNode != nil)
			return (this->tree_max(curr->LeftNode));
		Node *tmp = curr->Parrent;
		while (tmp != nil && curr == tmp->LeftNode)
		{
			curr = tmp;
			tmp = tmp->Parrent;
		}
		return tmp;
	}

};

#endif
