#include <stdio.h>
#include "main.h"

/**
 * _isdigit - checks for a digit
 * @c: is the char to be checked
 * Return: 1 when char is digit otherwise is 0
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
