#include <stdio.h>
#include <stdlib.h>
typedef struct s_node
{
	int val;
	struct s_node *left;
	struct s_node *right;
}node;

void free_tree(node *p)
{
	if (p != NULL)
	{
		free_tree(p->left);
		free_tree(p->right);
		free(p);
	}
}

void tree_print(node *p)
{
	if (p != NULL)
	{
		tree_print(p->left);
		printf("%d\n", p->val);
		tree_print(p->right);
	}
}

node *tree_add(node *p, int x)
{


	if (p == NULL)
	{
		p = (node *)malloc(sizeof(node));
		p->left = NULL;
		p->right = NULL;
		p->val = x;
	}
	else if (x < p->val)
		p->left = tree_add(p->left, x);
	else if (x > p->val)
		p->right = tree_add(p->right, x);
	return p;

}

int main ()
{

	node *p = NULL;


	p = tree_add(p, 5);
	p = tree_add(p, 4);
	p = tree_add(p, 3);
	p = tree_add(p, 8);
	p = tree_add(p, 1);
	p = tree_add(p, 2);
	p = tree_add(p, 7);
	p = tree_add(p, 6);
	tree_print(p);

	free_tree(p);

}
