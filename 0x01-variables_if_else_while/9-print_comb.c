#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: a c program thar prints single digit numbers
 * with a space and ','
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int sd = 48;

	while (sd < 58)
	{
		putchar(sd);
		if (sd != 57)
		{
		putchar(44);
		putchar(32);
		}
		sd++;
	}
	putchar('\n');

	return (0);
}
