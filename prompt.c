#include "shell.h"

/**
 * prompt - prints the shell prompt
 */
void prompt(void)
{
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "($) ", 4);
}
