#include "shell.h"

/**
 * get_command_path - finds the full path for a command
 * @command: the command to find
 *
 * Return: the full path to command or NULL if not found
 */
char *get_command_path(char *command)
{
	char *path_env, *path_copy, *path_token, *full_path;
	struct stat st;

	if (command == NULL)
		return (NULL);
	path_env = _getenv("PATH");
	if (path_env == NULL)
		return (NULL);
	path_copy = strdup(path_env);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		full_path = malloc(strlen(path_token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, path_token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			if (access(full_path, X_OK) == 0)
				return (full_path);
			free(full_path);
			return (NULL);
		}
		free(full_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

