#include "search_algos.h"

/**
 * interpolation_search - searches for a value in an array of integers
 *              using the Interpolation search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: If value is not present in array, your function must return -1
 *              Otherwise, the index where the value is located.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;

	if (array == NULL)
		return (-1);

	low = 0;
	high = size - 1;

	while (low <= high)
	{
		pos = low + (((double)(value - array[low]) * (high - low)) /
				(array[high] - array[low]));

		if (pos >= size)
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			return (-1);
		}
		else
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);
		else if (array[pos] > value)
			high = pos - 1;
		else if (array[pos] < value)
			low = pos + 1;
	}
	return (-1);
}
