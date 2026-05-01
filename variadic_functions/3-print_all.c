#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything based on format
 * @format: list of types (c, i, f, s)
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	unsigned int i = 0;
	char *sep = "";
	va_list args;

	char c;
	int n;
	float f;
	char *s;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			c = va_arg(args, int);
			printf("%s%c", sep, c);
		}
		else if (format[i] == 'i')
		{
			n = va_arg(args, int);
			printf("%s%d", sep, n);
		}
		else if (format[i] == 'f')
		{
			f = va_arg(args, double);
			printf("%s%f", sep, f);
		}
		else if (format[i] == 's')
		{
			s = va_arg(args, char *);
			if (s == NULL)
				s = "(nil)";
			printf("%s%s", sep, s);
		}
		else
		{
			i++;
			continue;
		}

		sep = ", ";
		i++;
	}

	printf("\n");
	va_end(args);
}
