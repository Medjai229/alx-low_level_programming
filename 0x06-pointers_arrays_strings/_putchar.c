#include <unistd.h>
#include "main.h"
/**
 * _putchar - writes the character c
 * @c: is the char to print
 *
 * Return: (1) on success
 *	(-1) on error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
