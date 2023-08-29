#include "binary_trees.h"

/**
 * binary_tree_inorder - print a binary tre with inorder traversal
 * @tree: the tree to print
 * @func: the function that print
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	if (tree->left != NULL)
		binary_tree_inorder(tree->left, func);
	func(tree->n);
	if (tree->right != NULL)
		binary_tree_inorder(tree->right, func);
}
