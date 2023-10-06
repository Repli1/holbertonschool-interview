#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - Checks if a given linked list has a cycle in it.
 * @list: A pointer to the head of the linked list to check.
 * Return: 0 if no cycle, 1 if cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *current = list;
	listint_t *check = list;


	while (check != NULL)
	{
		while (current != NULL)
		{
			current = current->next;
			if (current == check)
				return (1);
		}
		check = check->next;
	}
	return (0);
}
