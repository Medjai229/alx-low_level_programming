#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: a c program that prints
 * all lowercase then uppercase alphabet letters
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char c = 'a';
	char C = 'A';

	while (c <= 'z')
	{
		putchar(c);
		c++;
	}
	while (C <= 'Z')
	{
		putchar(C);
		C++;
	}
	putchar('\n');

	return (0);
}
