#include <stdio.h>
#include "main.h"

/**
 * print_line - that draws a straight line in the terminal.
 * @n: the lenght of the line
 */

void print_line(int n)
{
	int i;

	for (i = 1; i <= n; i++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
