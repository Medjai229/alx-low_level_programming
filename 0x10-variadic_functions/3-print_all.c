#include "variadic_functions.h"

/**
 * printc - prints a character
 *
 * @arg: arguments to be printed
 */

void printc(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	printf("%c", c);
}

/**
 * printi - prints an integer
 *
 * @arg: arguments to be printed
 */

void printi(va_list arg)
{
	int i;

	i = va_arg(arg, int);
	printf("%d", i);
}

/**
 * printfl - prints a float
 *
 * @arg: arguments to be printed
 */

void printfl(va_list arg)
{
	float f;

	f = va_arg(arg, double);
	printf("%f", f);
}

/**
 * prints - prints a string
 *
 * @arg: arguments to be printed
 */

void prints(va_list arg)
{
	char *s;

	s = va_arg(arg, char *);

	if (s == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", s);
}

/**
 * print_all - prints anything
 *
 * @format: string contains symobls of the data types
 * @...: the arguments to be printed
 */

void print_all(const char * const format, ...)
{
	va_list all;
	int i = 0, j;
	char *sep = "";
	prt_t funcs[] = {{"c", printc}, {"i", printi},
	{"f", printfl}, {"s", prints}};

	va_start(all, format);

	while (format && (*(format + i)))
	{
		j = 0;

		while (j < 4 && *(format + i) != *(funcs[j].sym))
			j++;

		if (j < 4)
		{
			printf("%s", sep);
			funcs[j].func(all);
			sep = ", ";
		}
		i++;
	}
	printf("\n");

	va_end(all);
}
