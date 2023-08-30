#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate the binary tree to left
 *
 * @tree: node of the tree
 * Return: pointer to the node
 */

/*
* example 1:
* (098)--.
*      (128)--.
*           (402)
* Rotate-left 98
*   .--(128)--.
* (098)     (402)
* ----------------------------------
*  example 2:
*
*   .--(128)-------.
* (098)       .--(402)--.
*           (420)     (450)
* Rotate-left 128
*        .-------(402)--.
*   .--(128)--.       (450)
* (098)     (420)
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	/* auxiliar to store nodes*/
	binary_tree_t *aux1, *aux2;

	/* validate if a tree is NULL or not exist right child*/
	if (tree == NULL || tree->right == NULL)
		return (NULL);
	/* save the parent of the current node ex1: NULL, ex2: NULL*/
	aux1 = tree->parent;
	/* save the right child, ex1: 128, ex2: 402*/
	aux2 = tree->right;
	/* the new right child is the grandchild left ex1: 402, ex2: 420*/
	tree->right = aux2->left;
	/**
	 * validate if the grandchild left is diferent to NULL
	 * ex1: 402, ex2: 420
	 **/
	if (aux2->left != NULL)
		/* the new parent is the current tree, ex1: 128, ex2: 128 */
		aux2->left->parent = tree;
	/**
	 * rotate left
	 * the new left for aux2 is the current tree, ex1: 98, ex2: 128
	 **/
	aux2->left = tree;
	/* the new parent is aux2, ex1: 128, ex2: 402*/
	tree->parent = aux2;
	/* the new parent for aux2 is the old tree parent, ex1:NULL, ex2: NULL*/
	aux2->parent = aux1;
	/* return the new root */
	return (aux2);
}
