#include "binary_trees.h"

/**
 * binary_tree_insert_left - create a new node to the left of the parent
 * @parent: the parent of the node to create
 * @value: the value of the new node
 * Return: the new node created
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left;

	if (parent == NULL)
		return (NULL);
	new_left = binary_tree_node(parent, value);
	if (parent->left != NULL)
	{
		new_left->left = parent->left;
		new_left->left->parent = new_left;
	}
	parent->left = new_left;

	return (new_left);
}
