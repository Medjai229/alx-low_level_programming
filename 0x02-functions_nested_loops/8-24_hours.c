#include <stdio.h>
#include "main.h"
/**
 * jack_bauer - prints every minute from 00:00 to 23:59
 */

void jack_bauer(void)
{
	int hh = 0, mm;

	while (hh < 24)
	{
		mm = 0;

		while (mm < 60)
		{
			_putchar('0' + (hh / 10);
			_putchar('0' + (hh % 10);
			_putchar(':');
			_putchar('0' + (mm / 10);
			_putchar('0' + (mm % 10);
			_putchar('\n');
			mm++;
		}
		hh++;
	}
}
