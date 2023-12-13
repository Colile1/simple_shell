#include "shell.h"

/**
 * execute - Executes a command
 * @args: Null-terminated array of arguments
 *
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */
int execute(char **args)
{
    int status;

    if (args == NULL || args[0] == NULL)
    {
        /* An empty command was entered */
        return 1;
    }
    if (is_builtin(args[0]))
    {
        return handle_builtin(args);
    }

    status = launch(args);
    return status;
}

