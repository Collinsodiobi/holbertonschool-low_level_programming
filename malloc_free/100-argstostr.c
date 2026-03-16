#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all program arguments
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to new string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
    int i, j, len = 0, pos = 0;
    char *str;

    if (ac == 0 || av == NULL)
        return (NULL);

    /* calculate total length needed */
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
            len++;
        len++; /* for \n */
    }

    str = malloc(sizeof(char) * (len + 1)); /* +1 for '\0' */
    if (str == NULL)
        return (NULL);

    /* copy arguments into str */
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
            str[pos++] = av[i][j];
        str[pos++] = '\n';
    }

    str[pos] = '\0';
    return (str);
}
