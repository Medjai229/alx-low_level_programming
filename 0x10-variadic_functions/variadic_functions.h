#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct prt - a new type that defines a print
 *
 * @sym: the symbol that specifiy data type
 * @func: pointer to a function that prints argument according to the sym
 */

typedef struct prt
{
	char *sym;
	void (*func)(va_list arg);
} prt_t;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif /*VARIADIC_FUNCTIONS_H*/
