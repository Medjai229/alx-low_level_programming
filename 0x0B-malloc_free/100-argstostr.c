#include "main.h"

/**
 * argstostr - concatenates all the arguments of your program
 *
 * @ac: number of arg
 * @av: values of arg
 *
 * Return: a string with the arg stored in it and if it fails returns NULL
 */

char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, ci = 0, tl = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		if (av[i] != NULL)
		{
			tl += 1;
		for (j = 0; av[i][j] != '\0'; j++)
			tl++;
		}
	}

	str = malloc(tl + 1);

	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		if (av[i] != NULL)
		{
			for (j = 0; av[i][j] != '\0'; j++)
			{
				str[ci] = av[i][j];
				ci++;
			}
			str[ci] = '\n';
			ci++;
		}
	}
	str[ci] = '\0';
	return (str);
}
