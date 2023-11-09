#include "variadic_functions.h"

/**
 * print_numbers - prints numbers, followed by a new line
 *
 * @separator: the string to be printed between numbers
 * @n: number of arguments
 * @...: the arguments to be printed
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list p;
	unsigned int i;

	va_start(p, n);

	for (i = 0; i < n; i++)
	{
		printf("%i", va_arg(p, int));

		if (i != n - 1 && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");
}
