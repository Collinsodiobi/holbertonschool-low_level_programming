#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: the string to reverse
 */
void rev_string(char *s)
{
	int i = 0, j;
	char temp;

	/* find string length */
	while (s[i] != '\0')
		i++;

	/* reverse the string */
	j = i - 1;
	i = 0;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
