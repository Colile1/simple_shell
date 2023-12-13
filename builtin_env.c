#include "shell.h"

static int print_environment(void);

/**
 * builtin_env - Prints the current environment
 * @args: List of arguments. Not used in this function.
 *
 * Return: Always returns 1, to continue executing.
 */
int builtin_env(char **args)
{
	(void)args;
	return (print_environment());
}

/**
 * print_environment - Helper function to print the current environment
 *
 * Return: Always returns 1.
 */
static int print_environment(void)
{
	int i;

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

// Moved the `extern char **environ;` declaration to the header file to avoid extern in .c files.

