#include "main.h"
#include "_putchar.c"

/**
 * print_alphabet - prints the alphabet in lowercase
 *
 * Return: void
 */
void print_alphabet(void)
{
    for (char c = 'a'; c <= 'z'; c++)
    {
        _putchar(c);
    }
}
