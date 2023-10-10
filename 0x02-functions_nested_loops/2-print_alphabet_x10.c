#include <stdio.h>
#include "main.h"
/**
 * print_alphabet_x10 - a function that prints all alphabet in lowercase
 * 10 times
 */

void print_alphabet_x10(void)
{
	int i = 0;
	char c;

	while (i < 10)
	{
		c = 'a'
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		i++;
	}
	_putchar('\n');
}
