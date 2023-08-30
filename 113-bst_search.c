#include "binary_trees.h"
/**
 * bst_search - search value in a tree
 *
 * @tree: tree for search
 * @value: value to search
 * Return: pointer to the node with the value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);
	else
	{
		if (value < tree->n)
			bst_search((bst_t *)tree->left, value);
		else
			bst_search((bst_t *)tree->right, value);
	}
	return (NULL);
}
