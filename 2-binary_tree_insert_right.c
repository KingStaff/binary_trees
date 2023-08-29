#include "binary_trees.h"

/**
 * binary_tree_insert_right - create a new node to the right of the parent
 * @parent: the parent of the node to create
 * @value: the value of the new node
 * Return: the new node created
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right;

	if (parent == NULL)
		return (NULL);
	new_right = binary_tree_node(parent, value);
	if (parent->right != NULL)
	{
		new_right->right = parent->right;
		new_right->right->parent = new_right;
	}
	parent->right = new_right;

	return (new_right);
}
