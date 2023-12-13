#include "shell.h"

/**
 * split_line - Splits a line into tokens
 * @line: The line to be tokenized
 *
 * Return: NULL-terminated array of tokens
 */
char **split_line(char *line)
{
int bufsize = 64, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token, **tokens_backup;

if (!tokens)
{
fprintf(stderr, "split_line: allocation error\n");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\r\n\a");
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize *= 2;
tokens_backup = tokens;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
free(tokens_backup);
fprintf(stderr, "split_line: allocation error\n");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " \t\r\n\a");
}
tokens[position] = NULL;
return (tokens);
}
