#include <stdio.h>
#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 *
 * @s: the first string
 * @accept: the string that we wat to compare to s
 *
 * Return:the length i
 */

unsigned int _strspn(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != s[i]; j++)
		{
			if (accept[j] == '\0')
				return (i);
		}
	}
	return (i);
}
