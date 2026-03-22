#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer converted
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num = 0;

	/* handle signs */
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
			break;
		i++;
	}

	/* convert digits */
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}

	return (num * sign);
}
