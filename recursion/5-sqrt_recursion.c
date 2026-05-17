#include "main.h"

/**
 * helper - finds square root recursively
 * @n: number
 * @i: possible square root
 *
 * Return: square root or -1
 */

int helper(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns natural square root of a number
 * @n: number
 *
 * Return: square root or -1 if none
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (helper(n, 0));
}
