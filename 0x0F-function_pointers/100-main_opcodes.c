#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 *
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	int i, bytes;
	char *mainaddr;

	if (argc != 2)
		printf("Error\n"), exit(1);

	bytes = atoi(argv[1]);

	if (bytes < 0)
		printf("Error\n"), exit(2);

	mainaddr = (char *)main;

	for (i = 0; i < bytes - 1; i++)
		printf("%02hhx ", mainaddr[i]);

	printf("%02hhx\n", mainaddr[i]);

	return (0);
}
