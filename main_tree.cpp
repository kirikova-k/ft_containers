#include <iostream>
#include "Tree.hpp"

int main()
{
	int s[] = {10, 4, 7, 1, 12, 20, 9, 6, 3};

	Tree tree;
	for (int i = 0; i < 9; i++)
	{
		tree.insert(s[i]);
	}
	// tree.print();
	tree.print_like_tree();
	tree.erase(1);
	tree.erase(10);
	tree.print_like_tree();
	tree.erase(12);
	tree.print_like_tree();
	tree.erase(7);
	tree.print_like_tree();
	tree.erase(20);
	tree.print_like_tree();
	tree.erase(4);
	tree.erase(9);
	tree.print_like_tree();
	tree.erase(6);
	tree.print_like_tree();
	tree.erase(3);
	tree.print_like_tree();
	tree.insert(10);
	tree.print_like_tree();
	return 0;
}
