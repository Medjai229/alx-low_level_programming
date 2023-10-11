#include <stdio.h>
#include "main.h"
/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the number of the table
 */

void print_times_table(int n)
{
	int i, j, k;

	if (n <= 15 && n >= 0)
	{
		for (i = 0; i < n; i++)
		{
			_putchar('0');

			for (j = 1; j < n; j++)
			{
				k = i * j;

				_putchar(',');
				_putchar(' ');

				if (k < 10)
					_putchar(' ');
				if (k < 100)
					_putchar(' ');
				if (k >= 100)
				{
					_putchar('0' + (k / 100));
					_putchar('0' + (k / 10) % 10);
				}
				else if (k < 100 && k >= 10)
					_putchar('0' + (k / 10));

				_putchar('0' + (k % 10));
			}
			_putchar('\n');
		}
	}
}
