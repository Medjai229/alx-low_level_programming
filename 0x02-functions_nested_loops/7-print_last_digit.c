#include <stdio.h>
#include "main.h"
/**
 * print_last_digit - prints the last digit of any givien number
 * @n: is the num we want the last digit from
 *
 * Return: the last digit of the num
 */

int print_last_digit(int n)
{
	int i;

	if (n < 0)
		i = -1 * (n % 10);
	else
		i = n % 10;

	_putchar(i + '0');
	return (i);
}

