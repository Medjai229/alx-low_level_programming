#include <stdio.h>
#include "main.h"

/**
 * _isupper - checks for uppercase character
 * @c: is the char to be checked
 * Return: 1 when char is upper case otherwise is 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
