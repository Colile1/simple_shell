#include "shell.h"

/**
 * read_line - Reads a line from standard input.
 * @void: No parameters.
 *
 * Return: The line read from standard input.
 */
char *read_line(void)
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		if (feof(stdin))
			handle_end_of_file(line);
		else
			perror("read_line: getline");
		return (NULL);
	}

	return (line);
}

