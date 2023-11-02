#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _isdigit - checks if character is digit
 *
 * @ch: the character to check
 *
 * Return: 1 if digit otherwise 0
 */

int _isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * _strlen - finds the lenght of a string
 *
 * @str: the string to find its lenght
 *
 * Return: integer contains the lenght of the string
 */

int _strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;

	return (i);
}

/**
 * multi - multiply two strings
 *
 * @str1: the first string
 * @str2: the second string
 *
 * Return: the product of the two string multiplied
 */

char *multi(char *str1, char *str2)
{
    int l1, l2, i, j, a, b, pro, car = 0;
    char *res;

    l1 = _strlen(str1);
    l2 = _strlen(str2);

    res = (char *)malloc(l1 + l2 + 1);

    if (res == NULL)
    {
        printf("Error\n");
        exit(98);
    }

    for (i = 0; i < l1 + l2; i++)
        res[i] = '0';

    for (i = l1 - 1; i >= 0; i--)
    {
        a = str1[i] - '0';

        for (j = l2 - 1; j >= 0; j--)
        {
            b = str2[j] - '0';

            pro = (res[i + j + 1] - '0') + a * b + car;
            car = pro / 10;
            res[i + j + 1] = (pro % 10) + '0';
        }
        res[i] += car;
        car = 0;
    }
    
    res[l1 + l2] = '\0';

    return (res);
}


/**
 * main - multiply two numbers
 *
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *res;
	int i = 0, cd, tl;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	res = multi(argv[1], argv[2]);
	tl = _strlen(res);
	cd = 0;

	while (cd < tl)
	{
		if (res[cd])
			i = 1;

		if (i)
			_putchar(res[cd] + '0');
		cd++;
	}
	if (!i)
		_putchar('0');
	_putchar('\n');
	free(res);
	return (0);
}
