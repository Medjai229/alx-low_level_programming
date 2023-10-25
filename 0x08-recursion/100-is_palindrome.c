#include <stdio.h>
#include "main.h"

int is_palin(char *s, int st, int e);
int _strlen(char *s);

/**
 * is_palindrome - returns 1 if a string is a palindrome and 0 if not
 *
 * @s: the string to be checked
 *
 * Return:if string is palindrome 1 if not 0
 */

int is_palindrome(char *s)
{
	int i = _strlen(s);

	if (*s == 0)
		return (1);

	return (is_palin(s, 0, i - 1));
}

/**
 * is_palin - returns 1 if a string is a palindrome and 0 if not
 *
 * @s: the string to be checked
 * @st: start of the string
 * @e: end of the string
 *
 * Return:if string is palindrome 1 if not 0
 */


int is_palin(char *s, int st, int e)
{
	if (st >= e)
		return (1);
	else if (s[st] != s[e])
		return (0);

	return (is_palin(s, st + 1, e - 1));
}

/**
 * _strlen - returns the length of a string
 * @s: the string
 * Return: the lenght of the string
 */

int _strlen(char *s)
{
	int c = 0;

	if (*s > '\0')
	{
		c++;
		c += _strlen(s + 1);
	}
	return (c);
}
