#include "binary_trees.h"

/**
 * binary_tree_depth - function that see how deep is a node
 * @tree: the pointer to the tree
 * Return: the deep of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t deep = 1;

	if (tree == NULL)
		return (0);

	if (tree->parent != NULL)
	{
		deep += binary_tree_depth(tree->parent);
		return (deep);
	}
	return (0);

}
