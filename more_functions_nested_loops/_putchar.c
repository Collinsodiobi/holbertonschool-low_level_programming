#include <unistd.h>
#include "main.h"

/**
 * _putchar - écrit le caractère c sur stdout
 * @c: caractère à écrire
 *
 * Return: 1 si succès, -1 sinon
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
