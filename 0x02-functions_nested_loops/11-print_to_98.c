#include <stdio.h>
#include "main.h"
/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: is the num starts to count from to 98
 */

void print_to_98(int n)
{
	int i, j;

	if (n < 98)
	{
		for (i = n; i <= 98; i++)
		{
			if (i != 98)
				printf("%i, ", i);
			else if (i == 98)
				printf("%i\n", i);
		}
	}
	else if (n > 98)
	{
		for (j = n; j >= 98; j--)
		{
			if (j != 98)
				printf("%i, ", i);
			else if (i == 98)
				printf("%i\n", i);
		}
	}
	else if (n == 98)
		printf("%i\n", n)
}
