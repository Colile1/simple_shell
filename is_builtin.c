#include "shell.h"

/**
 * is_builtin - Checks if the command is a built-in function
 * @command: The command to be checked
 *
 * Return: 1 if it is a built-in command, 0 otherwise
 */
int is_builtin(char *command)
{
    /* Array of built-in command names */
    char *builtins[] = {
        "cd",
        "help",
        "exit",
        "env",
        NULL
    };
    int i;

    /* Loop through the array of built-in commands */
    for (i = 0; builtins[i] != NULL; i++)
    {
        /* If command matches a built-in, return 1 */
        if (_strcmp(command, builtins[i]) == 0)
            return (1);
    }
    /* If no match was found, return 0 */
    return (0);
}
