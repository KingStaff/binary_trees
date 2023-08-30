#include "binary_trees.h"
#include <limits.h>
/**
 * binary_tree_aux - validate value between limits
 *
 * @tree: node of the tree
 * @min: min limit value
 * @max: max limit value
 *
 * Return: 1 if is a binary tree, else 0
 **/
int binary_tree_aux(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (binary_tree_aux(tree->left, min, tree->n - 1) &&
			binary_tree_aux(tree->right, tree->n + 1, max));

}

/**
 * binary_tree_is_bst - validate if tree is a Binary Search Tree
 *
 * @tree: node of the tree
 * Return: 0 if tree is null, call auxiliar function
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_aux(tree, INT_MIN, INT_MAX));
}
