#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: a c program that prints all lowercase alphabet letters
 * except q and e
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		if (c == 'q'|| c == 'e')
		{
			c++;
		}
		putchar(c);
		c++;
	}
	putchar('\n');

	return (0);
}
