#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: prints the first 50 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	/*assiging the ints*/
	int i;
	unsigned long f1 = 1;
	unsigned long f2 = 2;
	unsigned long sum = f1 + f2;

	/*printing the first 2 numbers*/
	printf("%lu, ", f1);
	printf("%lu, ", f2);

	/*for loop that will print the 48 remaining numbers*/
	for (i = 3; i <= 50; i++)
	{
		/*prints the sum*/
		printf("%lu, ", sum);

		/*assiging the new f1 and f2*/
		f1 = f2;
		f2 = sum;

		/*the sum of the new f1 and f2*/
		sum = f1 + f2;
	}

	printf("\n");

	return (0);
}
