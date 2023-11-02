#include <stdio.h>
#include <stdlib.h>

/**
 * is_positive_int - checks if the string is a positive integer
 *
 * @str: the string to be checked
 *
 * Return: if all char are digits return 1 (true) if not return 0 (false)
 */

int is_positive_int(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * _atoi - convert a strig to an integer
 *
 * @str: the string to be converted
 *
 * Return: an integer
 */

int _atoi(const char *str)
{
	int res = 0;

	while (*str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

/**
 * main - multiplies two positive numbers
 *
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char *n1;
	char *n2;
	int res;

	(void)argc;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	n1 = argv[1];
	n2 = argv[2];

	if (!is_positive_int(n1) || !is_positive_int(n2))
	{
		printf("Error\n");
		exit(98);
	}

	res = _atoi(n1) * _atoi(n2);
	printf("%d\n", res);

	return (0);
}
