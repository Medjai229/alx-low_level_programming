#include <stdio.h>
#include "main.h"

/**
 * _strchr - locates a character in a string
 *
 * @s: the string
 * @c: the char want to be located
 *
 * Return: pointer to s
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}
	return ('\0');
}

