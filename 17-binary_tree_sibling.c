#include "binary_trees.h"

/**
 * binary_tree_sibling - return sibling of the tree
 *
 * @node: node of the tree
 * Return: node sibling or NULL if not exist
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	/* validate if not have siblings*/
	if (node->parent == NULL || node->parent->left == NULL
		|| node->parent->right == NULL)
		return (NULL);
	/* validate if not is the same node*/
	if (node != node->parent->left)
			/* return left node*/
		return (node->parent->left);
	/*return right node*/
	return (node->parent->right);
}
