#include "search_algos.h"

/**
 * exponential_search - searches for a value in an array of integers
 *              using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: If value is not present in array, your function must return -1
 *              Otherwise, the index where the value is located.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, low, high, mid;

	if (array == NULL)
		return (-1);

	for (i = 1; i < size && array[i] <= value; i *= 2)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	low = i / 2;
	high = i < size ? i : size - 1;

	printf("Value found between indexes [%ld] and [%ld]\n", low, high);

	while (low <= high)
	{
		mid = (low + high) / 2;

		printf("Searching in array: %d", array[low]);
		for (i = low + 1; i <= high; i++)
			printf(", %d", array[i]);
		printf("\n");

		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value)
			high = mid - 1;
		else if (array[mid] < value)
			low = mid + 1;
	}
	return (-1);
}

