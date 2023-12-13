#include "shell.h"

/**
 * handle_builtin - Handles the execution of built-in commands
 * @args: Null-terminated array of arguments
 *
 * Return: 1 if the command executed successfully, 0 otherwise
 */
int handle_builtin(char **args)
{
	if (args == NULL || args[0] == NULL)
		return (0);

	if (_strcmp(args[0], "cd") == 0)
		return (builtin_cd(args));
	else if (_strcmp(args[0], "help") == 0)
		return (builtin_help(args));
	else if (_strcmp(args[0], "exit") == 0)
		return (builtin_exit(args));
	else if (_strcmp(args[0], "env") == 0)
		return (builtin_env(args));

	return (0);
}

