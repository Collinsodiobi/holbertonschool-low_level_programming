#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: starting number
 */
void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		for (i = n; i <= 98; i++)
		{
			if (i != n)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (i >= 100 || i <= -100)
				_putchar((i / 100) + '0');
			if (i >= 10 || i <= -10)
				_putchar(((i / 10) % 10) + '0');
			_putchar((i % 10 < 0 ? -(i % 10) : i % 10) + '0');
		}
	}
	else
	{
		for (i = n; i >= 98; i--)
		{
			if (i != n)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (i >= 100 || i <= -100)
				_putchar((i / 100) + '0');
			if (i >= 10 || i <= -10)
				_putchar(((i / 10) % 10) + '0');
			_putchar((i % 10 < 0 ? -(i % 10) : i % 10) + '0');
		}
	}
	_putchar('\n');
}
