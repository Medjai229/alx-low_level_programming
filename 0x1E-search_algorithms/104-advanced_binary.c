#include "search_algos.h"

/**
 * recursive_binary_search - searches for a value in an array of integers
 *              using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @low: the first index in the array
 * @high: the last index in the array
 * @value: the value to search for
 *
 * Return: If value is not present in array, your function must return -1
 *              Otherwise, the first index where the value is located.
 */
int recursive_binary_search(int *array, size_t low, size_t high, int value)
{
	size_t i, mid;

	if (low <= high)
	{
		mid = (low + high) / 2;

		printf("Searching in array: %d", array[low]);
		for (i = low + 1; i <= high; i++)
			printf(", %d", array[i]);
		printf("\n");

		if (array[mid] == value && (mid == low || array[mid - 1] != value))
			return (mid);
		if (array[mid] >= value)
			return (recursive_binary_search(array, low, mid, value));
		return (recursive_binary_search(array, mid + 1, high, value));
	}
	return (-1);
}

/**
 * advanced_binary - searches for a value in an array of integers
 *              using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: If value is not present in array, your function must return -1
 *              Otherwise, the first index where the value is located.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (recursive_binary_search(array, 0, size - 1, value));
}
