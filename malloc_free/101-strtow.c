#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the number of words in a string
 * @str: the string
 * Return: number of words
 */
int count_words(char *str)
{
    int count = 0, i = 0;

    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i] && str[i] != ' ')
        {
            count++;
            while (str[i] && str[i] != ' ')
                i++;
        }
    }
    return (count);
}

/**
 * strtow - splits a string into words
 * @str: input string
 * Return: pointer to array of words, or NULL
 */
char **strtow(char *str)
{
    int i = 0, j, k, word_len, words;
    char **result;

    if (!str || str[0] == '\0')
        return (NULL);

    words = count_words(str);
    if (words == 0)
        return (NULL);

    result = malloc(sizeof(char *) * (words + 1));
    if (!result)
        return (NULL);

    for (i = 0, k = 0; k < words; k++)
    {
        while (str[i] == ' ')
            i++;

        word_len = 0;
        while (str[i + word_len] && str[i + word_len] != ' ')
            word_len++;

        result[k] = malloc(sizeof(char) * (word_len + 1));
        if (!result[k])
        {
            /* free previously allocated words */
            while (k-- > 0)
                free(result[k]);
            free(result);
            return (NULL);
        }

        for (j = 0; j < word_len; j++)
            result[k][j] = str[i + j];
        result[k][j] = '\0';
        i += word_len;
    }

    result[words] = NULL;
    return (result);
}
