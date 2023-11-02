#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 *
 * @b: the size of the memory
 *
 * Return: a pointer with the size given
 */

void *malloc_checked(unsigned int b)
{
	int *x = malloc(b);

	if (x == 0)
		exit(98);

	return (x);
}
