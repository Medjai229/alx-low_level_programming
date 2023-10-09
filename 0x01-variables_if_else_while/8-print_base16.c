#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: a c program that prints base16 on order
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int b16 = 48;

	while (b16 < 103)
	{
		putchar(b16);
		if (b16 == 57)
		{
			b16 += 39;
		}

		b16++;
	}

	putchar('\n');

	return (0);
}
