#include <iostream>
#include "Tree.hpp"

int main()
{
	int s[] = {10, 4, 7, 1, 12, 20, 9, 5, 6, 3};

	Tree tree;
	for (int i = 0; i < 9; i++)
	{
		tree.insert(s[i]);
	}

	tree.print_like_tree();
	// tree.erase(1);
	tree.erase(7);
	// tree.print_like_tree();
	// tree.erase(12);
	// tree.print_like_tree();
	// tree.erase(7);
	// tree.print_like_tree();
	// tree.erase(20);
	// tree.print_like_tree();
	// tree.erase(4);
	// tree.erase(9);
	// tree.print_like_tree();
	// tree.erase(1);
	// tree.print_like_tree();
	// tree.erase(6);
	// tree.print_like_tree();
	// tree.erase(3);
	// tree.print_like_tree();
	// tree.insert(10);
	tree.print_like_tree();

	// Node *tmp = tree.find_node(4);
	// std::cout << tree.predecesor(tmp)->Data << "\n";
	// std::cout << tree.succesor(tmp)->Data << "\n";
	// std::cout << tree.tree_max(tmp)->Data << "\n";
	// std::cout << tree.tree_min(tmp)->Data << "\n";


	return 0;
}
// Node *replace = this->succesor(curr->RightNode);
		// replace->Parrent = curr->Parrent;
		// replace->LeftNode = curr->LeftNode;
		// replace->RightNode = curr->RightNode;
		// while (replace->LeftNode)
		// 	replace = replace->LeftNode;
		// int replace_val = replace->Data;
		// erase(key);
