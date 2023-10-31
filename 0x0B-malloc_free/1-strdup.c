#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 *
 * @str: the string to be copied
 *
 * Return: the copied string or if it fails return null
 */

char *_strdup(char *str)
{
	int i = 0, y;
	char *cs;

	if (str == NULL)
		return (NULL);

	while (str[i] != '\0')
		i++;

	cs = malloc(sizeof(char) * (i + 1));

	for (y = 0; y < i; y++)
		cs[y] = str[y];

	if (cs == NULL)
		return (NULL);

	return (cs);
}
