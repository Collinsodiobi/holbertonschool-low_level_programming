#include "main.h"

/**
 * print_triangle - affiche un triangle de # de taille `size`
 * @size: taille du triangle
 *
 * Return: rien
 */
void print_triangle(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= size; i++)
	{
		/* imprime les espaces avant les # */
		for (j = 1; j <= size - i; j++)
			_putchar(' ');

		/* imprime les # */
		for (j = 1; j <= i; j++)
			_putchar('#');

		_putchar('\n');
	}
}
