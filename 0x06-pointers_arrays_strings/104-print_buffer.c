#include <stdio.h>
#include "main.h"

/**
 * print_buffer - prints a buffer
 *
 * @b: buffer
 * @size: bytes size
 */

void print_buffer(char *b, int size)
{
	int i, j, n = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	while (n < size)
	{
		if (size - n < 10)
			j = size - n;
		else
			j = 10;

		printf("%08x: ", n);

		for (i = 0; i < 10 ; i++)
		{
			if (i < j)
				printf("%02x", *(b + n + i));
			else
				printf("  ");

			if (i % 2)
			{
				printf(" ");
			}
		}
		for (i = 0; i < j; i++)
		{
			int a = *(b + n + i);

			if (a < 32 || a > 132)
				a = '.';

			printf("%c", a);
		}
		printf("\n");
		n = n + 10;
	}
}
