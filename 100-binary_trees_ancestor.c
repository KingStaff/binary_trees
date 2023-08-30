#include "binary_trees.h"

/**
 * binary_tree_depth - function that see how deep is a node
 * @tree: the pointer to the tree
 * Return: the deep of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t deep = 1;

	if (tree == NULL)
		return (0);

	if (tree->parent != NULL)
	{
		deep += binary_tree_depth(tree->parent);
		return (deep);
	}
	return (0);
}

/**
 * binary_trees_ancestor - function that finds the lowest common ancestor
 *                         of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                const binary_tree_t *second)
{
    size_t depth_first = 0, depth_second = 0;
    binary_tree_t *aux1, *aux2;

    /* validate nodes if are NULL*/
    if (first == NULL || second == NULL)
        return (NULL);
    
    /*validate if they have the same parent*/
    if (first->parent == second->parent)
        return (first->parent);
    
    /* assign auxiliary variables */
    aux1 = first->parent;
    aux2 = second->parent;
    
    /* validate if the first node is equal to the parent of the second node*/
    if (first == aux2)
        return (aux2);
    /* validate if the second node is equal to the parent of the first node*/
    else if (second == aux1)
        return (aux1);
    
    /* validate depth of the nodes */
    depth_first = binary_tree_depth(aux1);
    depth_second = binary_tree_depth(aux2);
    
    /* move the auxiliaries and call recursion */
    if (depth_first != depth_second)
    {
        if (depth_first < depth_second)
            aux2 = aux2->parent;
        else
            aux1 = aux1->parent;
        
        if (aux1 == aux2)
            return (aux1);
        
        return binary_trees_ancestor(aux1, aux2);
    }
    
    return (NULL);
}
