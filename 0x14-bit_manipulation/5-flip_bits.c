#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to flip to get from n to m.
 * @n: The first number
 * @m: The second number
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_res;
	unsigned int c = 0;

	xor_res = n ^ m;

	while (xor_res > 0)
	{
		c += xor_res & 1;
		xor_res >>= 1;
	}

	return (c);
}
