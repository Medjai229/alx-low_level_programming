#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _isdigit - checks if character is digit
 *
 * @ch: the character to check
 *
 * Return: 1 if digit otherwise 0
 */

int _isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * _strlen - finds the lenght of a string
 *
 * @str: the string to find its lenght
 *
 * Return: integer contains the lenght of the string
 */

int _strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;

	return (i);
}

/**
 * multi - multiply two strings
 *
 * @str1: the first string
 * @str2: the second string
 *
 * Return: the product of the two string multiplied
 */

char *multi(char *str1, char *str2)
{
	char *r;
	int l1, l2, a, b, c, x;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	r = malloc(a = x = l1 + l2);
	if (!r)
		printf("Error\n"), exit(98);
	while (a--)
		r[a] = 0;

	for (l1--; l1 >= 0; l1--)
	{
		if (!_isdigit(s1[l1]))
		{
			free(r);
			printf("Error\n"), exit(98);
		}
		a = s1[l1] - '0';
		c = 0;

		for (l2 = _strlen(s2) - 1; l2 >= 0; l2--)
		{
			if (!_isdigit(s2[l2]))
			{
				free(r);
				printf("Error\n"), exit(98);
			}
			b = s2[l2] - '0';

			c += r[l1 + l2 + 1] + (a * b);
			r[l1 + l2 + 1] = c % 10;

			c /= 10;
		}
		if (c)
			r[l1 + l2 + 1] += c;
	}
	return (r);
}


/**
 * main - multiply two numbers
 *
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *res;
	int i = 0, cd, tl;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	res = multi(argv[1], argv[2]);
	tl = _strlen(res);
	cd = 0;

	while (cd < tl)
	{
		if (res[cd])
			i = 1;

		if (i)
			_putchar(res[cd] + '0');
		cd++;
	}
	if (!i)
		_putchar('0');
	_putchar('\n');
	free(res);
	return (0);
}
