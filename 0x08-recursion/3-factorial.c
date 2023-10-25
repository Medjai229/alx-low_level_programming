#include <stdio.h>
#include "main.h"

/**
 * factorial - returns the factorial of a given number
 *
 * @n: the number we want to get the fac for
 *
 * Return: the result
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n < 1)
		return (1);
	return (n * factorial(n - 1));
}
