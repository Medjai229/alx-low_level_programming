#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of the number 612852475143
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	long long largestprime = -1, i = 2, n = 612852475143;

	while (i * i <= n)
	{
		while (n % i == 0)
		{
			largestprime = i;
			n = n / i;
		}
		i++;
	}
	if (n > 1)
	{
		largestprime = n;
	}
	printf("%lld\n", largestprime);

	return (0);
}

