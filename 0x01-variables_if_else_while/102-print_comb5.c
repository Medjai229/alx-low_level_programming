#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: a c program that prints all combinations
 * of two two digit numbers
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int fd = 0, sd;

	while (fd < 100)
	{
		sd = fd;
		while (sd < 100)
		{
			if (fd != sd)
			{
				putchar((fd / 10) + 48);
				putchar((fd % 10) + 48);
				putchar(32);
				putchar((sd / 10) + 48);
				putchar((sd % 10) + 48);

				if (fd != 98 || sd != 99)
				{
					putchar(44);
					putchar(32);
				}
			}
			sd++;
		}
		fd++;
	}
	putchar('\n');

	return (0);
}
