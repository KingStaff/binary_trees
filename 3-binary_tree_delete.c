#include "binary_trees.h"

/**
 * binary_tree_delete - function that deletes a tree
 * @tree: the tree to delete
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	while (1)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			tree->parent = NULL;
			free(tree);
			return;
		}
		if (tree->left != NULL)
		{
			binary_tree_delete(tree->left);
			tree->left = NULL;
		}
		else
		{
			binary_tree_delete(tree->right);
			tree->right = NULL;
		}
	}
}
