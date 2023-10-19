#include <stdio.h>
#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 *
 * @a: the array
 * @n: number of elements in the array
 */

void reverse_array(int *a, int n)
{
	int i, rev;

	for (i = 0; i < n--; i++)
	{
		rev = a[i];
		a[i] = a[n];
		a[n] = rev;
	}
}
