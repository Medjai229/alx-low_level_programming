#include <stdio.h>
#include "main.h"

int nat_sqrt(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number
 *
 * @n: the number to get the square root for
 *
 * Return: the square root if there's not natural sqaure root returns -1
 */

int _sqrt_recursion(int n)
{
	return (nat_sqrt(n, 1));
}

/**
 * nat_sqrt - returns the natural square root of a number
 *
 * @n: the number to get the square root for
 * @i: the square root
 *
 * Return: the square root if there's not natural sqaure root returns -1
 */

int nat_sqrt(int n, int i)
{
	if (i * i == n)
		return (i);
	else if (i * i > n)
		return (-1);
	else
		return (nat_sqrt(n, i + 1));
}
