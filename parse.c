#include "shell.h"

/**
 * parse - Parses the input into an executable and its arguments
 * @input: Input string to parse
 * @env: Null-terminated array of environment variables
 * 
 * Return: Null-terminated array of executable and arguments, or NULL on failure
 */
char **parse(char *input, char **env)
{
    char **args = NULL;
    int bufsize = 64, position = 0;
    char *token;
    char *delimiters = " \t\r\n\a";

    if (!input)
    {
        return (NULL);
    }

    args = malloc(bufsize * sizeof(char *));
    if (!args)
    {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, delimiters);
    while (token != NULL)
    {
        args[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize *= 2;
            args = realloc(args, bufsize * sizeof(char *));
            if (!args)
            {
                perror("Allocation error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, delimiters);
    }
    args[position] = NULL;

    if (args[0][0] != '/' && args[0][0] != '.')
    {
        char *cmd_path = find_path(args[0], env);
        if (cmd_path)
        {
            args[0] = cmd_path;
        }
        else
        {
            free(args);
            perror("Command not found");
            return (NULL);
        }
    }

    return (args);
}
