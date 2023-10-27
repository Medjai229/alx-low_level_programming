#include <stdio.h>
#include "main.h"

/**
 * _memcpy -  copies memory area
 *
 * @dest: memory to be pasted
 * @src: memory to be copied
 * @n: number of bytes
 *
 * Return: copied memory dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
