#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all its parameters
 *
 * @n: number of arg
 * @...: the arguments to be summed
 *
 * Return: the sum of all arguments
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int i;
	va_list p;

	va_start(p, n);

	for (i = 0; i < n; i++)
		sum += va_arg(p, int);

	va_end(p);

	return (sum);
}
