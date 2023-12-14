#include "shell.h"

/**
 * environment_init - Initializes the environment
 * @env: Array of strings representing the environment
 */

void environment_init(char **env)
{
char **environ;
int i, count = 0;

for (i = 0; env[i] != NULL; i++)
count++;

environ = duplicate_environment(env, count);
if (!environ)
{
perror("malloc");
exit(EXIT_FAILURE);
}
}

/**
 * duplicate_environment - Helper function to duplicate environment
 * @env: Array of strings representing the environment
 * @count: Number of environment variables in env
 *
 * Return: A newly allocated environment array
 */
char **duplicate_environment(char **env, int count)
{
char **new_env;
int i;

new_env = malloc(sizeof(char *) * (count + 1));
if (!new_env)
return (NULL);

for (i = 0; i < count; i++)
{
new_env[i] = _strdup(env[i]);
if (!new_env[i])
{
perror("strdup");
while (--i >= 0)
free(new_env[i]);
free(new_env);
return (NULL);
}
}

new_env[count] = NULL;
return (new_env);
}
