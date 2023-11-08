#include "3-calc.h"

/**
 * main - performs simple operations
 *
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int result;
	int (*func)(int, int);

	func = get_op_func(argv[2]);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	if (!func)
	{
		printf("Error\n");
		exit(99);
	}

	if ((argv[2][0] == '/' || argv[2][0] == '%') && atoi(argv[3]) == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = func(atoi(argv[1]), atoi(argv[3]));
	printf("%d\n", result);
	return (0);
}
