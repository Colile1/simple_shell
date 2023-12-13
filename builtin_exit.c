#include "shell.h"

/**
 * builtin_exit - exits the shell
 * @args: array of arguments, the first is "exit" and the next can be the status
 *
 * Return: status value if specified, otherwise success (0)
 */
int builtin_exit(char **args)
{
	int status = 0;

	if (args[1]) /* if status is provided */
	{
		status = _atoi(args[1]);
		if (status == -1) /* if conversion failed */
		{
			perror("exit: Illegal number");
			return (2);
		}
	}

	exit(status);
}
