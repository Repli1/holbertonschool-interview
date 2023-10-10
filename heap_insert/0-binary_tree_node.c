#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Add a node to a binary tree.
 * @parent: The parent of the new node.
 * @value: The value of the new node.
 * Return: A pointer to the new node or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	return (new);
}
