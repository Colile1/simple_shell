#include <stdio.h>
#include <stdlib.h>

/**
 * read_input - Reads input from the user using getline
 *
 * Return: Pointer to the input string, or NULL on failure or if EOF is reached
 */
char *read_input(void)
{
char *line = NULL;
size_t bufsize = 0;
ssize_t nread;

nread = getline(&line, &bufsize, stdin);
if (nread == -1)
{
free(line);
return (NULL);
}

return (line);
}
