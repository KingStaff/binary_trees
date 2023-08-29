#include "binary_trees.h"

/**
 * binary_tree_leaves - count the number of leaves
 *
 * @tree: node of the tree
 * Return: number of leaves, or 0 otherwise
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		leaves += binary_tree_leaves(tree->left);
	if (tree->right)
		leaves += binary_tree_leaves(tree->right);
	if (tree->left == NULL && tree->right == NULL)
	{
		leaves++;
		return (leaves);
	}
	return (leaves);

}
