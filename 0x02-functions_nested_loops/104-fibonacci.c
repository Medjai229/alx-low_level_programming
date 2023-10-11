#include <stdio.h>
#include "main.h"
/**
 * numLength - returns the length of string
 * @num: operand num
 *
 * Return: number of digits
 */

int numLength(int num)
{
	int l = 0;

	if (!num)
		return (1);
	while (num)
	{
		num = num / 10;
		l += 1;
	}

	return (l);
}

/**
 * main - Entry point
 *
 * Description: prints the first 98 fib numbers starting with 1 and 2
 *
 * Return: Always 0 (Succuess)
 */

int main(void)
{
	int c, init;
	unsigned long f1 = 1, f2 = 2, sum, mx = 100000000, flo = 0, f2o = 0, sumo = 0;

	for (c = 1; c <= 98; c++)
	{
		if (flo > 0)
			printf("%lu", flo);
		init = numLength(mx) - 1 - numLength(f1);

		while (flo > 0 && init > 0)
		{
			printf("%d", 0);
			init--;
		}

		printf("%lu", f1);

		sum = (f1 + f2) % mx;
		sumo = flo + f2o + (f1 + f2) / mx;
		f1 = f2;
		flo = f2o;
		f2 = sum;
		f2o = sumo;

		if (count != 98)
			printf(", ");
		else
			printf("\n");
	}

	return (0);
}


