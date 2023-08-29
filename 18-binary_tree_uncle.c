#include "binary_trees.h"

/**
 * binary_tree_uncle - return the uncle of the node
 *
 * @node: is a node to find the uncle
 *
 * Return: the uncle of the node or NULL if not exist
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* validate node, parent and grandfathers exist*/
	if (node == NULL || node->parent == NULL ||
		node->parent->parent == NULL)
		return (NULL);
	/* validate if not is the same parent node and id exist*/
	if (node->parent != node->parent->parent->left &&
		node->parent->parent->left != NULL)
		return (node->parent->parent->left);
	/* validate if not is the same parent node and id exist*/
	if (node->parent != node->parent->parent->right &&
		node->parent->parent->right != NULL)
		return (node->parent->parent->right);
	return (NULL);

}
