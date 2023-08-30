#include "binary_trees.h"

/**
 * binary_tree_is_complete - return if ia binary tree is complete
 *
 * @tree: the tree to check
 *
 * Return: 1 if is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{	int height_left = 0, height_right = 0, balance;
	int retorn_left = 0, retorn_right = 0;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_perfect(tree))
		return (1);
	balance = binary_tree_balance(tree);
	if (balance < 0)
		return (0);
	if (tree->left == NULL)
	{
		height_left = -1, retorn_left = 1;
	}
	else
		height_left = (int)binary_tree_height(tree->left);
	if (tree->right == NULL)
	{	height_right = -1, retorn_right = 1;
	}
	else
		height_right = (int)binary_tree_height(tree->right);
	if (height_left < height_right || (height_left - 1) > height_right)
		return (0);
	if ((height_left - 1) == height_right)
	{
		if (binary_tree_is_perfect(tree->right) == 0)
			return (0);
		retorn_right = 1;
		retorn_left = binary_tree_is_complete(tree->left);
	}
	else if (height_left == height_right)
	{
		if (binary_tree_is_perfect(tree->left) == 0)
			return (0);
		retorn_left = 1;
		retorn_right = binary_tree_is_complete(tree->right);
	}
	if (retorn_right == 0 || retorn_left == 0)
		return (0);
	else
		return (1);
}
/**
 * binary_tree_balance - function that validate of a tree
 * @tree: the pointer to a tree
 *
 * Return: the balance of tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 1;
	int right = 1;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL)
		left -= 1;
	else
		left += binary_tree_height(tree->left);

	if (tree->right == NULL)
		right -= 1;
	else
		right += binary_tree_height(tree->right);
	return (left - right);
}
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
		return (1);

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
		leaves++;
		return (leaves);
	return (leaves);

}
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
