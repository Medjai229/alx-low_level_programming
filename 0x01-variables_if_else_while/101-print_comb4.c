#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: a c program that prints a 3 diff digit number
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int f = 48, s, t;

	while (f < 58)
	{
		s = 49;

		while (s < 58)
		{
			t = 50;

			while (t < 58)
			{
				if (f != s && f != t && s != t && f < s && f < t && s < t)
				{
					putchar(f);
					putchar(s);
					putchar(t);

					if (f != 55 || s != 56 || t != 57)
					{
						putchar(44);
						putchar(32);
					}
				}
				t++;
			}
			s++;
		}
		f++;
	}

	putchar('\n');

	return (0);
}
