#include <stdio.h>
#include "main.h"

/**
 * leet - encodes a string into 1337
 *
 * @c: input value
 *
 * Return: c
 */

char *leet(char *c)
{
	int i, j;
	char s1[] = "AEOTL";
	char s2[] = "43071";

	for (i = 0; c[i] != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (c[i] == s1[j] || c[i] == s1[j] + 32)
			{
				c[i] = s2[j];
			}
		}
	}
	return (c);
}

