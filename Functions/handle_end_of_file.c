#include "shell.h"

/**
 * handle_end_of_file - handles the end of file condition in the shell
 * @line: the current input line
 */
void handle_end_of_file(char *line)
{
    if (line == NULL)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "\n", 1);
        exit(EXIT_SUCCESS);
    }
}
