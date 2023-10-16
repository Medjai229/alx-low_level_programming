#include "main.h"

/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0), to the buffer pointed to by dest
 * @dest: the paste string
 * @src: the copy string
 * Return: the value of dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	do
	{
		dest[i] = src[i];
		i++;
	}
	while (src[i] != '\0');

	return (dest);
}
