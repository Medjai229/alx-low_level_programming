#include "variadic_functions.h"

/**
 * print_strings - prints strings, followed by a new line
 *
 * @separator: the string to be printed between numbers
 * @n: number of arguments
 * @...: the strings to be printed
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ps;
	unsigned int i;
	char *s;

	va_start(ps, n);

	for (i = 0; i < n; i++)
	{
		s = va_arg(ps, char *);

		if (s != NULL)
			printf("%s", s);
		else
			printf("(nil)");

		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");
}
