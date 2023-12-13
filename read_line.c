#include "shell.h"

/**
 * read_line - Reads a line of input from stdin
 * Return: The line read from stdin
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t nread;

    nread = getline(&line, &bufsize, stdin);
    if (nread == -1)
    {
        free(line);
        line = NULL;
    }

    return line;
}
