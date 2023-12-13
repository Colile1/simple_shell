#include "shell.h"

/**
 * launch - executes the program by creating a new process
 * @args: array of arguments. The first one is the program to execute
 *
 * Return: 1 to continue execution, -1 on error
 */
int launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error");
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
