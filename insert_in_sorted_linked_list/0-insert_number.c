#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Function that inserts a node in a sorted linked list.
 * @head: A pointer to the first node of the list.
 * @number: Number to insert in the node.
 * Return: The new node.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;
	listint_t *new = malloc(sizeof(listint_t));

	current = *head;

	while (number > current->next->n)
	{
		current = current->next;
	}
	new->n = number;
	new->next = current->next;
	current->next = new;
	return (new);
}
