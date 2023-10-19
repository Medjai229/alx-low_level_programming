#include <stdio.h>
#include "main.h"

/**
 * _strcat - concatenates two strings
 *
 * @dest: the first string
 * @src: the second string
 *
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;

	while (dest[i])
	{
		c++;
	}

	for (j = 0; src[j]; j++)
	{
		dest[i++] = src[j];
	}

	return (dest);
}
