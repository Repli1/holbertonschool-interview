#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - Function that inserts node in a sorted linked list
 * @head: Pointer to the first node of the list
 * @number: Number to insert in the node
 * Return: The new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;
	listint_t *new = malloc(sizeof(listint_t));

	if (*head == NULL)
		return (NULL);
	current = *head;
	if (number < current->n)
	{
		new->n = number;
		new->next = *head;
		*head = new;
	}
	while (current->next && number > current->next->n)
	{
		current = current->next;
	}
	new->n = number;
	new->next = current->next;
	current->next = new;

	return (new);
}
