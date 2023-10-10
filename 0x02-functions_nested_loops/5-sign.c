#include <stdio.h>
#include "main.h"
/**
 * print_sign - prints the sign of a number
 * @n: is the number that prints its sign
 *
 * Return:1 if num is positive and -1 if num is negative and 0 if num is 0
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}

