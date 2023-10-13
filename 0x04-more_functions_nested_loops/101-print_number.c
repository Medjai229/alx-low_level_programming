#include <stdio.h>
#include "main.h"

/**
 * print_number - prints an integer
 * @n: is the number to be printed
 */

void print_number(int n)
{
	unsigned int n1 = n;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n1;
	}

	if ((n1 / 10) > 0)
	{
		print_number(n1 / 10);
	}
	_putchar ('0' + (n1 % 10));
}
