#ifndef TREE_HPP
#include <iostream>
#include <stack>
#include "Node.hpp"

#define _RED "\033[1;31m"
#define DEFAULT "\033[0;37m"

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
		{
			if (curr->color == RED)
				std::cout <<_RED;
			else
				std::cout <<DEFAULT;
			std::cout << curr->Data;

		}
		if (curr != root)
			std::cout << '(' << curr->Parrent->Data << ')';
		std::cout << std::endl;
		print_ltree(curr->RightNode);
		tabs -=5;
		std::cout <<DEFAULT;
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

	void transplant(Node *curr, Node *parent_tmp)
	{
		if (curr->LeftNode == nil)
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
	}

	void	rotate_right(Node *x)
	{
		Node *y;
			y = x->LeftNode;
		x->LeftNode = y->RightNode;
		if (!is_nil(y->RightNode))
			y->RightNode->Parrent = x;
		y->Parrent = x->Parrent;
		if (x->Parrent == NULL) // x->Parrent == nil??
			root = y;
		else if (x == x->Parrent->LeftNode)
			x->Parrent->LeftNode = y;
		else
			x->Parrent->RightNode = y;
		y->RightNode = x;
		x->Parrent = y;
	}

	void rotate_left(Node *x)
	{
		Node *y;
		y = x->RightNode;
		x->RightNode = y->LeftNode;
		if (!is_nil(y->LeftNode))
			y->LeftNode->Parrent = x;
		y->Parrent = x->Parrent;
		if (x->Parrent == NULL)// x->Parrent == nil??
			root = y;
		else if (x == x->Parrent->LeftNode)
			x->Parrent->LeftNode = y;
		else
			x->Parrent->RightNode = y;
		y->LeftNode = x;
		x->Parrent = y;
	}

	bool is_nil(Node *curr)
	{
		return curr == nil;
	}

	void insert_fixup(Node *curr)
	{
		if (curr != root && curr->Parrent != root)
		{
			while (curr != root && curr->Parrent->color != BLACK)
			{
				if (curr->Parrent == curr->Parrent->Parrent->LeftNode)//if curr left child
				{
					Node *uncle = curr->Parrent->Parrent->RightNode;
					if (uncle->color != BLACK)
					{
						curr->Parrent->color = BLACK;
						uncle->color = BLACK;
						curr->Parrent->Parrent->color = RED;
						curr = curr->Parrent->Parrent;
					}
					else
					{
						if (curr == curr->Parrent->RightNode)
						{
							curr = curr->Parrent;
							rotate_left(curr);///
						}
						curr->Parrent->color = BLACK;
						curr->Parrent->Parrent->color = RED;
						rotate_right(curr->Parrent->Parrent);///
					}
				}
				else
				{
					Node *uncle = curr->Parrent->Parrent->LeftNode;
					if (uncle->color == RED)
					{
						curr->Parrent->color = BLACK;
						uncle->color = BLACK;
						curr->Parrent->Parrent->color = RED;
						curr = curr->Parrent->Parrent;
					}
					else
					{
						if (curr == curr->Parrent->LeftNode)
						{
							curr = curr->Parrent;
							rotate_right(curr);//
						}
						curr->Parrent->color = BLACK;
						curr->Parrent->Parrent->color = RED;
						rotate_left(curr->Parrent->Parrent);
					}
				}
			}
		}
		root->color = BLACK;
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
		while (curr != nil && curr->Data != key)
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
			root = new Node(key);
			root->Parrent = nil;
			root->LeftNode = nil;
			root->RightNode = nil;
			tree_size = 1;
			root->color = BLACK;
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
				curr->color = RED;/////fixup_insert
				++tree_size;
				insert_fixup(curr);
				return;
			}
			if (curr->Data < key && curr->RightNode == nil)
			{
				curr->RightNode = new Node(key);
				curr->RightNode->Parrent = curr;
				curr->RightNode->LeftNode = nil;
				curr->RightNode->RightNode = nil;
				curr->color = RED;/////fixup_insert
				++tree_size;
				insert_fixup(curr);
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
		else if (curr->LeftNode == nil || curr->RightNode == nil)
			transplant(curr, parent_tmp); //case 2/3: left child or right child
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
