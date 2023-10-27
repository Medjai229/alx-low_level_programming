#include <stdio.h>
#include "main.h"

/**
 * _strncpy - copies the string pointed to by src
 * including the terminating null byte (\0), to the buffer pointed to by dest
 *
 * @dest: the paste string
 * @src: the copy string
 * @n: most bytes
 *
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
