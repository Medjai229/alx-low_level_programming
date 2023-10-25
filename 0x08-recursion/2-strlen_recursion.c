#include <stdio.h>
#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 *
 * @s: the string to get the lenght of
 *
 * Return: lenght of the string c
 */

int _strlen_recursion(char *s)
{
	int c = 0;

	if (*s > '\0')
	{
		c++;
		c += _strlen_recursion(s + 1);
	}
	return (c);
}

