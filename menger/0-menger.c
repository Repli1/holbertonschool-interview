#include <stdio.h>
#include <math.h>
/**
 * checker - Function that checks if a spot needs a #.
 * @level: The level of the menger sponge.
 * @i: X coordinate of the spot.
 * @j: Y coordinate of the spot.
 * Return: 0 if doesn't need, 1 if needs.
 */
int checker(int level, int i, int j)
{
	int current = pow(3, level - 1);

	while (level > 0)
	{
		if (i / current % 3 == 1 && j / current % 3 == 1)
			return (0);
		level = level - 1;
		current = pow(3, level - 1);
	}
	return (1);
}
/**
 * menger - Function that prints a menger sponge.
 * @level: The level of the sponge to print.
 */
void menger(int level)
{
	int i, j;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	for (i = 0; i < pow(3, level); i++)
	{
		for (j = 0; j < pow(3, level); j++)
			if (checker(level, i, j) == 0)
				printf(" ");
			else
				printf("#");
		printf("\n");
	}
}
