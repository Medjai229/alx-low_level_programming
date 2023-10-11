#include <stdio.h>
#include "main.h"
/**
 * print_last_digit - prints the last digit of any givien number
 * @n: is the num we want the last digit from
 *
 * Return : Always 0 (Success)
 */

int print_last_digit(int n)
{
	int i = n % 10;

	_putchar('0' + i);
	return (0);
}

