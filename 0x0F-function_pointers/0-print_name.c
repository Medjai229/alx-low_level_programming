#include "function_pointers.h"

/**
 * print_name - prints a name
 *
 * @name: name to be printed
 * @f: pointer to the function that will print the name
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
	{
		f(name);
	}
}
