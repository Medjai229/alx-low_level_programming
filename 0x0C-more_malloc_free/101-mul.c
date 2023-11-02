#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _puts - prints a string
 *
 * @str: the string to be printed
 */

void _puts(const char *str)
{
	int i = 0;

	while(str[i])
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * is_positive_int - checks if the string is a positive integer
 *
 * @str: the string to be checked
 *
 * Return: if all char are digits return 1 (true) if not return 0 (false)
 */

int is_positive_int(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * print_int - print an int
 *
 * @n: the int to be printed
 */

void print_int(unsigned long int n)
{
	unsigned long int div = 1, i = 0, res;

	while (n / div > 9)
	{
		i++;
		div *= 10;
	}

	while (div >= 1)
	{
		res = n / div;
		_putchar('0' + res);
		n %= div;
		div /= 10;
	}
}

/**
 * _atoi - convert a strig to an integer
 *
 * @str: the string to be converted
 *
 * Return: an integer
 */

int _atoi(const char *str)
{
	int res = 0;

	while (*str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

/**
 * main - multiplies two positive numbers
 *
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char *n1;
	char *n2;
	int res;

	(void)argc;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	n1 = argv[1];
	n2 = argv[2];

	if (!is_positive_int(n1) || !is_positive_int(n2))
	{
		printf("Error\n");
		exit(98);
	}

	res = _atoi(n1) * _atoi(n2);
	print_int(res);
	_putchar('\n');

	return (0);
}
