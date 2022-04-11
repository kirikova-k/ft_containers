#include <iostream>
// #include "Tree.hpp"
#include "RBTree.hpp"

int main()
{
	int s[] = {6, 3, 7, 8, 2, 10, 4, 1, 12, 20, 9, 5};

	Tree tree;
	for (int i = 0; i < 11; i++)
	{
		tree.insert(s[i]);
		tree.print_like_tree();
	}

	tree.print_like_tree();
	// tree.erase(1);
	// tree.print_like_tree();
	// tree.erase(6);
	// tree.insert(6);
	// tree.print_like_tree();
	// tree.erase(3);
	// tree.print_like_tree();
	// tree.erase(20);
	// tree.print_like_tree();
	// tree.erase(10);
	// tree.erase(7);
	// tree.erase(8);
	// tree.print_like_tree();

	// Node *tmp = tree.find_node(10);
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
