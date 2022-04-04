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
		if (curr)
		{
			print_tree(curr->LeftNode);
			std::cout << curr->Data << " ";
			print_tree(curr->RightNode);
		}
	}

	void print_ltree(Node *curr)
	{
		if (!curr) return;
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
		if (curr)
		{
			delete_tree(curr->LeftNode);
			delete_tree(curr->RightNode);
			delete curr;
		}
	}

public:
	Tree()
	{
		root = NULL;
		tree_size = 0;
	}

	Tree(int key)
	{
		root = new Node(key);
		tree_size = 1;
	}

	~Tree() {delete_tree(root);}

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
		if (!root)
		{
			root = new Node(key);
			tree_size = 1;
			return;
		}
		Node *curr = root;
		while (curr && curr->Data != key)
		{
			if (curr->Data > key && curr->LeftNode == NULL)
			{
				curr->LeftNode = new Node(key);
				curr->LeftNode->Parrent = curr;
				++tree_size;
				return;
			}
			if (curr->Data < key && curr->RightNode == NULL)
			{
				curr->RightNode = new Node(key);
				curr->RightNode->Parrent = curr;
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
		Node *parent_tmp = NULL;
		while (curr && curr->Data != key)
		{
			parent_tmp = curr;//
			if (curr->Data > key)
				curr = curr->LeftNode;
			else
				curr = curr->RightNode;
		}
		if (!curr)
			return;
		if (curr->LeftNode == NULL || curr->RightNode == NULL)
		{
			if (curr->LeftNode == NULL && curr->RightNode == NULL) //если это лист
			{
				if (curr == root)
				{
					root = NULL;
					tree_size = 0;
					return;
				}
				if (curr == curr->Parrent->LeftNode)
					curr->Parrent->LeftNode = NULL;
				else
					curr->Parrent->RightNode = NULL;
			}
			else if (curr->LeftNode == NULL)
			{//вместо curr подвешивается его правое поддерево
				if (curr == root)
				{
					curr->RightNode->Parrent = NULL;
					root = curr->RightNode;
				}
				if (parent_tmp && parent_tmp->LeftNode == curr)
					parent_tmp->LeftNode = curr->RightNode;
				if (parent_tmp && parent_tmp->RightNode == curr)
					parent_tmp->RightNode = curr->RightNode;
				curr->RightNode->Parrent = parent_tmp;
			}
			else if (curr->RightNode == NULL)
			{//вместо curr подвешивается его левое поддерево
				if (curr == root)
				{
					curr->LeftNode->Parrent = NULL;
					root = curr->LeftNode;
				}
				if (parent_tmp && parent_tmp->LeftNode == curr)
					parent_tmp->LeftNode = curr->LeftNode;
				if (parent_tmp && parent_tmp->RightNode == curr)
					parent_tmp->RightNode = curr->LeftNode;
				curr->LeftNode->Parrent = parent_tmp;
			}
			delete curr;
			tree_size--;
			return;
		}
		//У элемента есть два потомка, тогда на место элемента поставим
		//наименьший элемент из его правого поддерева
		Node *replace = curr->RightNode;
		while (replace->LeftNode)
			replace = replace->LeftNode;
		int replace_val = replace->Data;
		erase(replace_val);
		curr->Data = replace_val;

	}

	int size() {return tree_size;}
	// Node *tree_max()
	// {
	// 	Node *curr = root;
	// 	while (curr)
	// 		curr

	// }
};

#endif
