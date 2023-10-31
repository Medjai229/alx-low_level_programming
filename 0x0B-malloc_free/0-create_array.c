#include "main.h"

/**
 * create_array - creates an array of chars
 * and initializes it with a specific char
 *
 * @size: size of the array
 * @c: the charactar
 *
 * Return: pointer to the array if it fails return null
 */

char *create_array(unsigned int size, char c)
{
	char *ch = malloc(size);

	if (size == 0 || ch == 0)
		return (NULL);

	while (size--)
		ch[size] = c;

	return (ch);
}
