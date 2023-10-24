#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix of integers
 *
 * @a: the array
 * @size: size of array
 */

void print_diagsums(int *a, int size)
{
	int i, r1 = 0, r2 = 0;

	for (i = 0; i < size; i++)
	{
		r1 += a[i * size + i];
		r2 += a[i * size + (size - i - 1)];
	}

	printf("%i, %i\n", r1, r2);
}
