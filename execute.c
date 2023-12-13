#include shell.h

/**
 * execute - Executes a command
 * @args: Array of argument strings
 *
 * Return: Status of execution
 */

int execute(char **args)
{
	int status = 1;

	if (args[0] == NULL)
	{

		return (1);
	}
	if (is_builtin(args[0]))
	{
		status = handle_builtin(args);
	}
	else
	{
		status = launch(args);
	}

	return (status);
}
