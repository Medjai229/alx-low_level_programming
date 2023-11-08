#include "function_pointers.h"

/**
 * int_index - searches for an integer
 *
 * @array: array of intergers
 * @size: size of array
 * @cmp: ponter to function
 *
 * Return: if any number match return its index of not return -1
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && size && cmp)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
			{
				return (i);
			}
		}
	}
	return (-1);
}
