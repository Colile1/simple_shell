#include "shell.h"

/**
 * is_builtin - Checks if the command is a built-in function
 * @command: The command to be checked
 *
 * Return: 1 if it is a built-in command, 0 otherwise
 */
int is_builtin(char *command)
{
char *builtins[] = {
"cd",
"help",
"exit",
"env",
NULL
};
int i;

for (i = 0; builtins[i] != NULL; i++)
{
if (_strcmp(command, builtins[i]) == 0)
return (1);
}
return (0);
}
