#include <stdio.h>
#include "main.h"

/**
 * rot13 - encodes a string using rot13
 *
 * @c: input value
 *
 * Return: c
 */

char *rot13(char *c)
{
	int i, j;
	char normal[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char r13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; c[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (c[i] == normal[j])
			{
				c[i] = r13[j];
				break;
			}
		}
	}
	return (c);
}

