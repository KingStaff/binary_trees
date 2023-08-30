#include "binary_trees.h"
/**
 * array_to_bst - values to store in the tree
 *
 * @array: values to store in the tree
 * @size: Number of elements in the array
 * Return: pointer to the node
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *node = NULL;
	size_t i = 0;

	/* validate if array is NULL*/
	if (array == NULL)
		return (NULL);
	/* iterate over array*/
	while (i < size)
	{
		/* call function to insert node, send root and value*/
		bst_insert(&node, array[i]);
		i++;
	}
	/* return root*/
	return (node);
}
