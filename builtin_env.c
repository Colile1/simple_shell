#include "shell.h"

/**
 * builtin_env - Prints the current environment
 * @args: List of arguments. Not used in this function.
 *
 * Return: Always returns 1, to continue executing.
 */
int builtin_env(char **args)
{
	extern char **environ;
	int i;

	(void)args; /* args not used */

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	return (1);
}

/**
 * _strlen - Returns the length of a string
 * @s: String to count
 *
 * Return: String length
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
		count++;

	return (count);
}
