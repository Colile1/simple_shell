#include "shell.h"

/**
 * unset_env_var - Removes an environment variable
 * @name: Name of the environment variable to remove
 *
 * Return: 0 on success, -1 on failure
 */
int unset_env_var(char *name)
{
	extern char **environ;
	char **env, **new_env;
	size_t name_len;
	int i = 0, j = 0;

	if (!name)
		return (-1);

	name_len = _strlen(name);
	env = environ;

	/* Count the number of remaining environment variables */
	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
		return (-1);

	/* Copy all environment variables except the one to be removed */
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, name_len) != 0 || environ[i][name_len] != '=')
		{
			new_env[j++] = environ[i];
		}
	}
	new_env[j] = NULL;

	/* Set the new environment */
	environ = new_env;
	return (0);
}

/**
 * _strlen - Calculate the length of a string
 * @s: String to measure
 *
 * Return: Length of the string
 */
static int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _strncmp - Compare two strings up to n bytes
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes to compare
 *
 * Return: 0 if same, else difference between the bytes
 */
static int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
