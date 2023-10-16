#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string to be printed
 */

void rev_string(char *s)
{
	char tmp = s[0];
	int i, c = 0;

	while (s[c] != '\0')
		c++;

	for (i = 0; i < c; i++)
	{
		c--;
		tmp = s[i];
		s[i] = s[c];
		s[c] = tmp;
	}
}
