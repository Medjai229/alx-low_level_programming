#include "main.h"

/**
 *
 *
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
		temp = s[i];
		s[i] = s[c];
		s[c] = tmp;
	}
}
