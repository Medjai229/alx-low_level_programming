#include <stdio.h>
#include "main.h"

/**
 * _strstr -  locates a substring
 *
 * @haystack: the string
 * @needle: the substring
 *
 * Return: the valure in haystack from the the needle
 */

char *_strstr(char *haystack, char *needle)
{
	int i;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
			return (haystack + i);
	}
	return (NULL);

}
