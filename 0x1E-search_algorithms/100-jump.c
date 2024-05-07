#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in an array of integers
 *              using the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: If value is not present in array, your function must return -1
 *              Otherwise, the index where the value is located.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, step, prev_index, curr_index;

	step = sqrt(size);
	prev_index = 0;
	curr_index = step;

	if (array == NULL)
		return (-1);

	printf("Value checked array[%ld] = [%d]\n", prev_index, array[prev_index]);

	while (curr_index < size && array[curr_index] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", curr_index, array[curr_index]);
		prev_index = curr_index;
		curr_index += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n"
			, prev_index, curr_index);

	for (i = prev_index; i <= curr_index && i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
