#include "binary_trees.h"

/**
 * binary_tree_nodes - function that count the nodes of a tree
 * @tree: the pointer to a tree
 * Return: the nodes of tree with at least 1 child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 1;

	if (tree == NULL)
		return (0);
	/*go to left of the tree*/
	if (tree->left != NULL)
		/* incremet number of nodes*/
		nodes += binary_tree_nodes(tree->left);
		/* increment number of nodes*/
	if (tree->right != NULL)
		nodes += binary_tree_nodes(tree->right);

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}
	/* if the node has a least child return counter*/
	return (nodes);
}
