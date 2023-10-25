#include <stdio.h>
#include "main.h"

int check_prime(int n, int i);

/**
 * is_prime_number - returns 1 if the input integer is a prime number
 * otherwise return 0
 *
 * @n: the number to be checked
 *
 * Return: 1 if the number is prime otherwise 0
 */

int is_prime_number(int n)
{
	return (check_prime(n, 2));
}

/**
 * check_prime - returns 1 if the input integer is a prime number
 * otherwise return 0
 *
 * @n: the number to be checked
 * @i: the number that is incremented
 *
 * Return: 1 if the number is prime otherwise 0
 */

int check_prime(int n, int i)
{
	if (i == n && n > 1)
		return (1);
	else if (n % i == 0 || n <= 1)
		return (0);
	else
		return (check_prime(n, i + 1));
}
