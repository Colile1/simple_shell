#include "shell.h"

/**
 * split_line - Splits a command line into tokens.
 * @line: The command line input.
 *
 * Return: Null-terminated array of tokens.
 */
char **split_line(char *line)
{
	char **tokens;
	size_t bufsize = 64, position = 0;
	char *token, **tokens_backup;

	if (!line)
		exit(EXIT_FAILURE);

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				free(tokens_backup);
				perror("allocation error");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return tokens;
}

