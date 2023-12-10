#include "shell.h"

/**
 * tokenize - Splits an input string into tokens.
 * @input: The string to be tokenized.
 *
 * Description: Tokenizes a string into an array of strings delimited by
 *              whitespace characters. The array of strings is
 *              null-terminated.
 * Return: A pointer to the array of tokenized strings or NULL if an error occurs.
 */
char **tokenize(char *input)
{
    char **tokens = NULL;
    size_t bufsize = 64;
    size_t position = 0;
    char *token;
    char *delimiters = " \t\r\n\a";

    if (!input)
    {
        return (NULL);
    }

    tokens = malloc(bufsize * sizeof(char *));
    if (!tokens)
    {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, delimiters);
    while (token != NULL)
    {
        tokens[position++] = token;

        if (position >= bufsize)
        {
            bufsize *= 2;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                perror("Reallocation error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, delimiters);
    }
    tokens[position] = NULL;

    return (tokens);
}
