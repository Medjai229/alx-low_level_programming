#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _isdigit - checks if character is digit
 *
 * @c: the character to check
 *
 * Return: 1 if digit otherwise 0
 */

int _isdigit(int ch)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - finds the lenght of a string
 *
 * @s: the string to find its lenght
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
 *
 */

char *multi(char *str1, char *str2)
{
	int l1, l2, i, j, a, b, pro, car = 0;
	char *res;

	l1 = _strlen(str1);
	l2 = _strlen(str2);

	res = malloc(l1 + l2);
	if (res == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i < l1 + l2; i++)
		res[i] = '0';

	for (i = l1 - 1; i >= 0; i--)
	{
		if (!_isdigit(str1[i]))
		{
			free(res);
			printf("Error\n");
			exit(98);
		}
		a = str1[i] - '0';

		for (j = l2 - 1; j >= 0; j--)
		{
			if (!_isdigit(str2[j]))
			{
				free(res);
				printf("Error\n");
				exit(98);
			}
			b = str2[j] - '0';
			pro = (res[i + j + 1] - '0') + a * b + car;
			res[i + j + 1] = (pro & 10) + '0';
			car = pro / 10;
		}

		res[i] += car;
	}

	while (*res == '0' && *(res + 1) != '\0')
		res++;

	return (res);
}
