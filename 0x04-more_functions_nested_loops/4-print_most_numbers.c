#include <stdio.h>
#include "main.h"

/**
 * print_numbers - prints the numbers from 0 to 9 expect 2 & 4
 * Return: void
 */

void print_numbers(void)
{
	char i;

	for (i = '0'; i <= '9'; i++)
	{
		if ( i != 2 || i != 4)
		_putchar(i);
	}

	_putchar('\n');
}
