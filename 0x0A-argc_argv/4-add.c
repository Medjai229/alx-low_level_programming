#include <stdio.h>
#include <stdlib.h>

/**
 * main - adds positive numbers
 *
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return: if one of the arg is not a digit return 1
 * if all arg are digits return 0
 */

int main(int argc, char *argv[])
{
	int i, c, s = 0;

	for (i = 1; i < argc; i++)
	{
		for (c = 0; argv[i][c]; c++)
		{
			if (argv[i][c] < '0' || argv[i][c] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		s += atoi(argv[i]);
	}
	printf("%d\n", s);
	return (0);
}


