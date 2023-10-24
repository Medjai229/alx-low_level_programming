#include <stdio.h>
#include "main.h"

/**
 * set_string - sets the value of a pointer to a char
 *
 * @s: the string to be pasted
 * @to: the string to be copied
 */

void set_string(char **s, char *to)
{
	*s = to;
}
