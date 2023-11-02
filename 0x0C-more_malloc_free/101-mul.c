#include "main.h"
#include <string.h>

/**
 * _isdigit - checks if character is digit
 *
 * @ch: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */

int _isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * _strlen - returns the length of a string
 *
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */

int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * multiply - multiply two big number strings
 *
 * @str1: the first number string
 * @str2: the second number string
 *
 * Return: the product big number string
 */

char *multiply(char *str1, char *str2)
{
	int l1, l2, i, j, a, b, carry, product;
	char *res;

	l1 = _strlen(str1), l2 = _strlen(str1);
	res = malloc(l1 + l2 + 1);
	if (res == NULL)
	{
		printf("Error\n"), exit(98);
	}
	for (i = 0; i < l1 + l2; i++)
		res[i] = '0';
	res[l1 + l2] = '\0';
	for (i = l1 - 1; i >= 0; i--)
	{
		if (!_isdigit(str1[i]))
		{
			free(res);
			printf("Error\n"), exit(98);
		}
		a = str1[i] - '0';
		carry = 0;

		for (j = l2 - 1; j >= 0; j--)
		{
			if (!_isdigit(str2[j]))
			{
				free(res);
				printf("Error\n");
				exit(98);
			}
			b = str2[j] - '0';
			product = (res[i + j + 1] - '0') + a * b + carry;
			res[i + j + 1] = (product % 10) + '0';
			carry = product / 10;
		}
		res[i] += carry;
	}
	while (*res == '0' && *(res + 1) != '\0')
		res++;
	return (res);
}

/**
 * main - multiply two big number strings
 *
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: Always 0 on success.
 */

int main(int argc, char **argv)
{
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	result = multiply(argv[1], argv[2]);

	if (*result == '\0')
		_putchar('0');
	else
		printf("%s\n", result);

	free(result);

	return (0);
}
