#include "main.h"

/**
 * array_range - creates an array of integers
 *
 * @min: the minimum value of the array
 * @max: the maximum value of the array
 *
 * Return: a pointer to array with values from min to max
 */

int *array_range(int min, int max)
{
	int *ary;
	int i;

	if (min > max)
		return (NULL);

	/*memory allocation*/

	ary = malloc(sizeof(int) * (max - min) + 1);

	if (ary == NULL)
		return (NULL);

	/*assinging the values to the array from min to max*/

	for (i = 0; min <= max; i++, min++)
		ary[i] = min;

	return (ary);
}

