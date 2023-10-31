#include "main.h"

/**
 * str_concat - concatenates two strings
 *
 * @s1: the first string
 * @s2: the second string
 *
 * Return: the two string concatenated or NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, x, y;
	char *conc;

	if (s1 == NULL || s2 == NULL)
		return (NULL);

	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;

	conc = malloc(sizeof(char) * (i + j + 2));

	if (conc == NULL)
		return (NULL);

	for (x = 0; x < i; x++)
		conc[x] = s1[x];

	for (y = 0; y < j; y++)
		conc[i + y] = s2[y];

	return (conc);
}
