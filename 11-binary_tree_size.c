#include "binary_trees.h"

/**
 * binary_tree_size - function that count the size of a tree
 * @tree: the pointer to a tree
 * Return: the size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
		return (0);
	/* go to end of left tree*/
	if (tree->left != NULL)
		/* increment size*/
		size += binary_tree_size(tree->left);
	/* go to end right tree*/
	if (tree->right != NULL)
		/* increment size*/
		size += binary_tree_size(tree->right);

	/* if node is a leaf */
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	/* return size*/
	return (size);
}
