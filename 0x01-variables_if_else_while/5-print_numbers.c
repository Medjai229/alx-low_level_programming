#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: a c program that prints single digit numbers
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int sd = 0;

	while (sd < 10)
	{
		printf("%i", sd);
		sd++;
	}
	printf("\n");

	return (0);
}

