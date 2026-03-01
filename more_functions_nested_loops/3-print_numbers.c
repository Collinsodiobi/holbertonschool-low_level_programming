#include "main.h"

/**
 * print_numbers - affiche les chiffres de 0 à 9 suivis d'un saut de ligne
 *
 * Return: rien
 */
void print_numbers(void)
{
	int i;

	for (i = 0; i < 10; i++)
		_putchar(i + '0');
	_putchar('\n');
}
