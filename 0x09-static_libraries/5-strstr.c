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
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = i; haystack[j] > '\0' && needle[j - i] > '\0'; j++)
		{
			if (haystack[j] != needle[j - i])
			{
				break;
			}
		}
		if (needle[j - i] == '\0')
		{
			return (haystack + i);
		}
	}
	return (0);

}
