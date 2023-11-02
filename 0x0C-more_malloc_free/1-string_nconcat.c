#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * and the second string with a number of bytes
 *
 * @s1: the first string
 * @s2: the second string
 * @n: number of bytes of the second string
 *
 * Return: a pointer which has 2 string copied into it
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int l1 = 0, l2 = 0, i, j;

	/*if null is passed treat it as an empty string*/

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/*find the lenght of each string*/

	while (s1[l1] != '\0')
		l1++;
	while (s2[l2] != '\0')
		l2++;

	/*memory allocation*/

	str = malloc(sizeof(char) * (l1 + n + 1));
	if (str == NULL)
		return (NULL);

	/*copy s1 to str*/

	for (i = 0; i < l1; i++)
		str[i] = s1[i];

	/*copy first n bytes of s2 to str*/

	for (j = 0; j < n; j++)
	{
		str[i] = s2[j];
		i++;
	}

	str[i] = '\0';
	return (str);
}
