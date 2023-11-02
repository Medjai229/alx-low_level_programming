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

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * print_int - print an int
 *
 * @n: the int to be printed
 */

void print_int(unsigned long int n)
{
	unsigned long int div = 1, i, res;

	for (i = 0; n / div > 9; i++, div *= 10)
		;


	for (; div >= 1; n %= div, div /= 10)
	{
		res = n / div;
		_putchar('0' + res);
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
	int sign = 1;
	unsigned long int res = 0, fn, i;

	for (fn = 0; !(str[fn] >= '0' && str[fn] <= '9'); fn++)
	{
		if (str[fn] == '-')
			sign *= -1;
	}

	for (i = fn; str[i] >= '0' && str[i] <= '9'; i++)
	{
		res = res * 10 + (str[i] - '0');
	}
	return (sign * res);
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
	(void)argc;

	if (argc != 3)
	{
		_puts("Error ");
		exit(98);
	}

	print_int(_atoi(argv[1]) * _atoi(argv[2]));
	_putchar('\n');

	return (0);
}
