#include "main.h"

/**
 * wordcount - counts the characters without spaces
 * @s: the string to count
 *
 * Return: n number of char
 */

int wordcount(char *s)
{
	int i, n = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == ' ')
		{
			if (s[i + 1] != ' ' && s[i + 1] != '\0')
				n++;
		}
		else if (i == 0)
			n++;
	}
	n++;
	return (n);
}

/**
 * strtow - splits a string into words
 *
 * @str: the string to be splited
 *
 * Return: char array of the words
 */

char **strtow(char *str)
{
	char **s;
	int n = 0, i = 0, j, wc = 0, k, l;

	if (str == NULL || *str == '\0')
		return (NULL);

	n = wordcount(str);

	if (n == 1)
		return (NULL);
	s = (char **)malloc(sizeof(char *) * n);
	if (s == NULL)
		return (NULL);
	s[n - 1] = NULL;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			for (j = 1; str[i + j] != ' ' && str[i + j]; j++)
				;
			s[wc] = (char *)malloc(sizeof(char) * (j + 1));
			if (s[wc] == NULL)
			{
				for (k = 0; k < wc; k++)
					free(s[k]);
				free(s[n - 1]);
				free(s);
				return (NULL);
			}
			for (l = 0; l < j; l++)
				s[wc][l] = str[i + l];
			s[wc][l] = '\0';
			wc++;
			i += j;
		}
		else
			i++;
	}
	return (s);
}
