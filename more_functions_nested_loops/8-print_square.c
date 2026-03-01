#include "main.h"

/**
 * print_square - dessine un carré de # dans le terminal
 * @size: taille du carré
 *
 * Return: rien
 */
void print_square(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			_putchar('#');
		_putchar('\n');
	}
}
