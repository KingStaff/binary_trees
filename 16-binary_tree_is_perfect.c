#include "binary_trees.h"

/**
 * binary_tree_is_perfect - validate if tree is full
 *
 * @tree : pointer to root
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaves = 0, height = 0;
	size_t tree_full = 1;
	size_t cont = 0;

	if (tree == NULL)
		return (0);

	/* return number of leaves*/
	leaves = binary_tree_leaves(tree);
	/* return height of the tree*/
	height = binary_tree_height(tree);
	/* calculate total leaves full tree*/
	while (cont < height)
	{
		tree_full *= 2;
		cont++;
	}
	/* validate if leaves is equal to awaiting total tree*/
	if (leaves == tree_full)
		return (1);
	return (0);
}

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
#include "binary_trees.h"

/**
 * binary_tree_height - function that count the height of a tree
 * @tree: the pointer to a tree
 * Return: the height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 1;
	size_t right = 1;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left += binary_tree_height(tree->left);
	if (tree->right != NULL)
		right += binary_tree_height(tree->right);

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}
	return (MAX(left, right));
}
