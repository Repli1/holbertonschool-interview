#include "lists.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * is_palindrome - Checks if a given linked list is a palindrome.
 * @head: Head node of the linked list to check.
 * Return: 0 if not a palindrome, 1 if palindrome.
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int n = 0, i = 0, j = 0;
	int *contents;
	int *inverse;

	if (*head == NULL)
		return (1);
	while (current != NULL)
	{
		n++;
		current = current->next;
	}
	j = n;
	current = *head;
	contents = malloc(sizeof(int) * n);
	inverse = malloc(sizeof(int) * n);
	while (current != NULL)
	{
		contents[i] = current->n;
		current = current->next;
		i++;
	}
	i = 0;
	while (j > 0)
	{
		j--;
		printf("The number is: %i\n", contents[j]);
		inverse[i] = contents[j];
		i++;
	}
	for (i = 0; i < n; i++)
	{
		if (contents[i] != inverse[i])
		{
			return (0);
		}
	}
	return (1);
}

