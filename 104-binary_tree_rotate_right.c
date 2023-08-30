#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate the binary tree to right
 *
 * @tree: node of the tree
 * Return: pointer to the node
 */

/*
* example 1:
*       .--(098)
*   .--(064)
* (032)
* Rotate-right 98
*   .--(064)--.
* (032)     (098)
* ----------------------------
* example 2:
*        .-------(064)--.
*   .--(032)--.       (098)
* (020)     (056)
* Rotate-right 64
*   .--(032)-------.
* (020)       .--(064)--.
*           (056)     (098)
**/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	/* auxiliar to store nodes*/
	binary_tree_t *aux1, *aux2;

	/* validate if a tree is NULL or not exist right child*/
	if (tree == NULL || tree->left == NULL)
		return (NULL);
	/* save the parent of the current node ex1: NULL, ex2: NULL*/
	aux1 = tree->parent;
	/* save the right child, ex1: 64, ex2: 32*/
	aux2 = tree->left;
	/* the new right child is the grandchild right ex1: NULL, ex2: 56*/
	tree->left = aux2->right;
	/**
	 * validate if the grandchild left is diferent to NULL
	 * ex1: NULL, ex2: 56
	 **/
	if (aux2->right != NULL)
		/* the new parent is the current tree, ex1: NA, ex2: 64 */
		aux2->right->parent = tree;
	/**
	 * rotate right
	 * the new right for aux2 is the current tree, ex1: 98, ex2: 64
	 **/
	aux2->right = tree;
	/* the new parent is aux2, ex1: 64, ex2: 32*/
	tree->parent = aux2;
	/* the new parent for aux2 is the old tree parent, ex1:NULL, ex2: NULL*/
	aux2->parent = aux1;
	/* return the new root */
	return (aux2);
}
