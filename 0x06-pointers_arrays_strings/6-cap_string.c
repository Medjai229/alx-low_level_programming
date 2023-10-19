#include <stdio.h>
#include "main.h"

/**
 * cap_string - capitalizes all words of a string.
 *
 * @str: the stting
 *
 * Return: a pointer to the changed string
 */

char *cap_string(char *str)
{
	int i = 0;

	while (str[i])
	{
		while (str[i] <= 'a' || str[i] >= 'z')
		{
			i++;
		}
		if (str[i - 1] == (' ' || '\t' || '\n' || ',' ||
		';' || '.' || '!' || '?' || '"' || '(' || ')' || '{' || '}') || i == 0)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

