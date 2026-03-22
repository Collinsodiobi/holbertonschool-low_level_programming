#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: the string to print
 */
void puts_half(char *str)
{
	int len = 0, i;

	/* Find the length of the string */
	while (str[len] != '\0')
		len++;

	/* Start from the middle (or middle+1 if odd) */
	i = (len % 2 == 0) ? len / 2 : (len + 1) / 2;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
