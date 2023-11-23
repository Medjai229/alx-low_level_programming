#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to string of 0 and 1
 *
 * Return: the converted number or 0 if b is null
 * or there is chars that are not 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int base = 1, res = 0, l = 0;

	if (b == NULL)
		return (0);

	while (b[l])
		l++;

	l = l - 1;

	while (l + 1)
	{
		if (b[l] != '0' && b[l] != '1')
			return (0);

		if (b[l] == '1')
			res += base;
		base *= 2;
		l--;
	}
	return (res);
}
