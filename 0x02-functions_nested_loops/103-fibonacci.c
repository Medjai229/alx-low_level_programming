#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: prints the sum of the even-valued terms
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	/*assiging the ints*/
	int i;
	unsigned long f1 = 0;
	unsigned long f2 = 1;
	unsigned long sum = f1 + f2;
	float totalsum;


	for (i = 0; ; i++)
	{
		if (sum > 4000000)
			break;
		if ((sum % 2) == 0)
			totalsum += sum;

		/*assiging the new f1 and f2*/
		f1 = f2;
		f2 = sum;

		/*the sum of the new f1 and f2*/
		sum = f1 + f2;
	}
	printf("%.0f\n", totalsum);

	return (0);
}
