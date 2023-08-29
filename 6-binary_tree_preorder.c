#include "binary_trees.h"

/**
 * binary_tree_preorder - print a binary tre with preorder traversal
 * @tree: the tree to print
 * @func: the function that print
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);

	if (tree->left != NULL)
		binary_tree_preorder(tree->left, func);
	if (tree->right != NULL)
		binary_tree_preorder(tree->right, func);
}
