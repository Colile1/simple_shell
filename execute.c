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
		/* An empty command was entered */
		return 1;
	}
	if (is_builtin(args[0]))
	{
		/* If the command is a built-in, handle it */
		status = handle_builtin(args);
	}
	else
	{
		/* Otherwise, launch the program */
		status = launch(args);
	}

	return status;
}
