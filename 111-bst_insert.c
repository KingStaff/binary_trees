#include "binary_trees.h"
/**
 * bst_insert - insert in a binary tree
 *
 * @tree: node of the tree
 * @value: value of node
 * Return: return the node insert or NULL if it fail
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node;

	if (*tree == NULL)
	{
		node = binary_tree_node(*tree, value);
		*tree = node;
	}
	else
	{
		if (value < (*tree)->n)
			if ((*tree)->left == NULL)
			{
				node = binary_tree_node(*tree, value);
				(*tree)->left = node;
				return (node);
			}
			else
				node = bst_insert(&(*tree)->left, value);
		else if (value > (*tree)->n)
			if ((*tree)->right == NULL)
			{
				node = binary_tree_node(*tree, value);
				(*tree)->right = node;
				return (node);
			}
			else
				node  = bst_insert(&(*tree)->right, value);
		else
			return (NULL);
	}
	return (node);
}
