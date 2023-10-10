#include <stdio.h>
#include "main.h"
/**
 * _islower - checks if the character is lowercase
 * @c: is the character to be checked
 *
 * Return: 1 if char is lowercase otherwise 0
 */

int _islower(int c);
{
	if ('a' <= c <= 'z')
		return (1);
	else
		return (0);
}
