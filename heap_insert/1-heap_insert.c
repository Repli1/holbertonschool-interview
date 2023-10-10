#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Add a node to a max heap.
 * @root: Double pointer to the root node of the heap.
 * @value: The value of the new node.
 * Return: A pointer to the new node or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = malloc(sizeof(heap_t)), *valid, *buffer = NULL;
	int i = 0;

	if (new == NULL)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;
	if (*root == NULL)
	{
		*root = new;
		return (new);
	}
	valid = *root;
	if (is_complete(*root) == 1)
	{
		while (valid->left)
			valid = valid->left;
	}
	else
		valid = search_parent(valid, valid, buffer);
	new->parent = valid;
	if (valid->left == NULL)
		valid->left = new;
	else
		valid->right = new;
	buffer = new;
	while (buffer->parent)
	{
		if (buffer->parent->n < buffer->n)
		{
			i = buffer->n;
			buffer->n = buffer->parent->n;
			buffer->parent->n = i;
			new = buffer->parent;
		}
		buffer = buffer->parent;
	}
	return (new);
}

/**
 * get_height - Gets the height of a heap.
 * @root: Pointer to the root of the heap.
 * Return: 0 if NULL pointer otherwise height of the heap.
 */
int get_height(heap_t *root)
{
	if (root == NULL)
		return (0);
	if (get_height(root->left) > get_height(root->right))
		return (get_height(root->left) + 1);
	return (get_height(root->right) + 1);
}

/**
 * is_complete - Checks if heap is complete.
 * @root: Pointer to the root node of the heap.
 * Return: -1 if NULL pointer, 0 if not complete, 1 if complete.
 */
int is_complete(heap_t *root)
{
	int depth = 1;
	heap_t *current = root;

	if (root == NULL)
		return (-1);
	while (current->right)
	{
		depth++;
		current = current->right;
	}
	if (depth == get_height(root))
		return (1);
	return (0);
}

/**
 * get_depth - Gets depth of a node.
 * @node: Pointer to the node.
 * Return: -1 if NULL pointer, otherwise depth of the node.
 */
int get_depth(heap_t *node)
{
	if (node == NULL)
		return (-1);
	if (node->parent)
		return (get_depth(node->parent) + 1);
	return (1);
}

/**
 * search_parent - Searchs for the correct node to be the parent node.
 * @root: Pointer to the root of the heap.
 * @current: Moving pointer for recursion, pass root again on call.
 * @buffer: Buffer to store the valid node for recursion (Pass NULL on call).
 * Return: A pointer to the found node.
 */
heap_t *search_parent(heap_t *root, heap_t *current, heap_t *buffer)
{
	if (current->left && buffer == NULL)
	{
		buffer = search_parent(root, current->left, buffer);
	}
	if (current->right && buffer == NULL)
	{
		buffer = search_parent(root, current->right, buffer);
	}
	if (check_node(root, current) == 1)
		return (current);
	return (buffer);
}

/**
 * check_node - Checks if a node is valid for search_parent.
 * @root: Pointer to the root node of the heap.
 * @node: Node to check.
 * Return: -1 if pointer is NULL, 0 if node is not valid, 1 if it is.
 */
int check_node(heap_t *root, heap_t *node)
{
	if (node == NULL)
		return (-1);
	if (node->left && (node->right == NULL))
		return (1);
	if (get_height(root) != get_depth(node) && !(node->left || node->right))
		return (1);
	return (0);
}
