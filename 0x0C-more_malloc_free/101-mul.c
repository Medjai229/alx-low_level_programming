#include "main.h"

/**
 * _isdigit - checks if character is digit
 *
 * @ch: the pointer to array of char
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(char *ch)
{
	int i = 0;

	while (ch[i])
	{
		if (ch[i] < '0' || ch[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * multiplyStrings - multiplies strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: result of multiplication
 */

int *multiplyStrings(char *s1, char *s2)
{
	int len1, len2, len, i, j, digit1, digit2, carry;
	int *result;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);


	if (!result)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		digit1 = s1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = s2[j] - '0';
			carry += result[i + j + 1] + (digit1 * digit2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
		result[i + len2 + 1] += carry;
	}

	return (result);
}

/**
 * main - multiply two big number strings
 *
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: Always 0 on success.
 */

int main(int argc, char *argv[])
{
	char *s1, *s2;
	int *result;
	int len, i, a = 0;

	s1 = argv[1], s2 = argv[2];
	len = _strlen(s1) + _strlen(s2) + 1;
	result = malloc(sizeof(int) * len);

	if (!result)
	{
		printf("Error\n");
		exit(98);
	}

	if (argc != 3 || !_isdigit(s1) || !_isdigit(s2))
	{
		printf("Error\n");
		exit(98);
	}

	result = multiplyStrings(s1, s2);

	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);

	return (0);
}

