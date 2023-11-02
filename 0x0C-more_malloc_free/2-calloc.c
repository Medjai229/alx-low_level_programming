#include "main.h"

/**
 * _calloc - allocates memory for an array, using malloc
 * with a memory of zero
 *
 * @nmemb: number of memory
 * @size: size of the memory
 *
 * Return: a poniter with a memory set to zero
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;

	/*if any input is 0 return null*/

	if (nmemb == 0 || size == 0)
		return (NULL);

	/*memory allocation*/

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	/*setting memory to 0*/

	for (i = 0; i < nmemb * size; i++)
		ptr[i] = 0;

	return (ptr);
}
