#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * find_path - Finds the full path for commands using PATH environment variable
 * @cmd: The command to find the path for
 * @env: The environment variables array
 *
 * Return: The full path to the command or NULL if not found
 */
char *find_path(char *cmd, char **env)
{
    char *path_env = NULL;
    char *path = NULL;
    char *full_path = NULL;
    char *token = NULL;

    for (int i = 0; env[i] != NULL; i++)
    {
        if (strncmp(env[i], "PATH=", 5) == 0)
        {
            path_env = env[i] + 5;
            break;
        }
    }

    if (path_env == NULL || cmd == NULL || cmd[0] == '\0')
    {
        return (NULL);
    }

    path = strdup(path_env);
    if (path == NULL)
    {
        perror("Error duplicating PATH");
        return (NULL);
    }

    token = strtok(path, ":");
    while (token != NULL)
    {
        full_path = malloc(strlen(token) + strlen(cmd) + 2);
        if (full_path == NULL)
        {
            free(path);
            perror("Error allocating space for full path");
            return (NULL);
        }

        sprintf(full_path, "%s/%s", token, cmd);

        if (access(full_path, X_OK) == 0)
        {
            free(path);
            return (full_path);
            }

        free(full_path);
        full_path = NULL;
        token = strtok(NULL, ":");
    }

    free(path);
    return (NULL);
}
