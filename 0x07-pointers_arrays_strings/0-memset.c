#include <stdio.h>
#include "main.h"

/**
 * _memset - fills memory with a constant byte
 *
 * @s: address of the memory to be filled
 * @b: the value
 * @n: number of bytes to be changed
 *
 * Return: the changed arrary s
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; i <= n; i++)
	{
		s[i] = b;
	}
	return (s);
}
