#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * is_palindrome - Checks if a given number is a palindrome.
 * @n: Number to check.
 * Return: 0 if not a palindrome, 1 if palindrome.
 */
int is_palindrome(unsigned long n)
{
	unsigned long m = n;
	int i = 0, j;

	if (n == 0)
		i++;
	while (m > 0)
	{
		m = m / 10;
		i++;
	}
	while (i > 0)
	{
		m = n;
		for (j = 0; j < (i - 1); j++)
		{
			m = m / 10;
		}
		if (m != (n % 10))
			return (0);
		for (; j >= 1; j--)
			m = m * 10;
		n = (n - n % 10 - m) / 10;
		i = i - 2;
	}
	return (1);
}
