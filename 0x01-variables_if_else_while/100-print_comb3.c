#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: a c program that prints 2 digits that are not the same
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int f = 48, s;

	while (f < 58)
	{
		s = 48;
		while (s < 58)
		{
			if (f != s && f < s)
			{
				putchar(f);
				putchar(s);

				if (f != 56 || s != 57)
				{
					putchar(44);
					putchar(32);
				}
			}
			s++;
		}
		f++;
	}

	putchar('\n');

	return (0);
}
