#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 *
 * @width: columbs of the table
 * @height: rows of the table
 *
 * Return: 2d array of intergers if it fails return NULL
 */

int **alloc_grid(int width, int height)
{
	int **tab;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	tab = malloc(sizeof(int **) * height);

	if (tab == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		tab[i] = malloc(sizeof(int *) * width);

		if (tab[i] == NULL)
		{
			for (j = 0; j < width; j++)
				free(tab[j]);
			free(tab);
			return (NULL);
		}

		for (j = 0; j <width; j++)
			tab[i][j] = 0;
	}
	return (tab);
}
