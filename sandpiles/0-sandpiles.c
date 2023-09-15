#include <stdio.h>

/**
 * sandpiles_sum - Function that prints the process of summing sandpiles
 * @grid1: First sandpile to sum
 * @grid2: Second sandpile to sum
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int grid3[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int check = 0;

	printf("=\n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid3[i][j] = grid1[i][j] + grid2[i][j];
	while (check == 0)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j < 2)
					printf("%i ", grid3[i][j]);
				else
					printf("%i\n", grid3[i][j]);
			}
		}
		check = 1;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid3[i][j] > 3)
				{
					grid3[i][j] = grid3[i][j] - 4;
					if (i > 0)
						grid3[i - 1][j] += 1;
					if (i < 2)
						grid3[i + 1][j] += 1;
					if (j > 0)
						grid3[i][j - 1] += 1;
					if (j < 2)
						grid3[i][j + 1] += 1;
					check = 0; } } }
		if (check == 0)
			printf("=\n"); }
}
