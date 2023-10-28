#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make change
 * for an amount of money
 *
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return:if number of arr is 1 return 0 otherwise return 1
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		int i, coins = 0, money = atoi(argv[1]);
		int change[] = {25, 10, 5, 2, 1};

		for (i = 0; i < 5; i++)
		{
			if (money >= change[i])
			{
				coins += money / change[i];
				money = money % change[i];
				if (money == 0)
					break;
			}
		}
		printf("%d\n", coins);
	}
	return (0);
}
