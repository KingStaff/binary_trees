#include "binary_trees.h"

/**
 * binary_tree_node - create a nodes for the tree
 *
 * @parent: parent of the node
 * @value: value for the node
 *
 * Return: new_node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
		/*pointer to new node*/
		binary_tree_t *new_node;

		/*allocate memory for the new node*/
		new_node = malloc(sizeof(binary_tree_t));
		if (new_node == NULL)
			return (NULL);
		/*assign values*/
		new_node->parent = parent;
		new_node->n = value;
		new_node->left = NULL;
		new_node->right = NULL;
		return (new_node);
}
