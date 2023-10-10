#include <stdio.h>
#include "main.h"
/**
 * print_alphabet - a function that prints all alphabet in lowercasee
 */

void print_alphabet(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		_putchar(c);
		c++;
	}
	_putchar('\n');
}
