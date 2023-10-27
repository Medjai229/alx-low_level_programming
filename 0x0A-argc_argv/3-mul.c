#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 *
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return: 0 if there is 2 arg otherwise 1
 */

int main(int argc, char *argv[])
{
	int s;

	if (argc == 3)
	{
		s = atoi(argv[1]) * atoi(argv[2]);
		printf("%i\n", s);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
