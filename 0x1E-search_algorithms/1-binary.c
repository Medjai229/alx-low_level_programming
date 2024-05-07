#include "search_algos.h"

/**
 * binary_search - searches for a value in an array of integers
 *              using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: If value is not present in array, your function must return -1
 *              Otherwise, the index where the value is located.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, low, high, mid;

	if (array == NULL)
		return (-1);

	low = 0;
	high = size - 1;
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
