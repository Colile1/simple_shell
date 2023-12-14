#include "shell.h"

/**
 * _getenv - Gets the value of an environment variable
 * @name: The name of the environment variable to find
 *
 * Description: Looks for the environment variable and returns
 * its value, if found. Otherwise, returns NULL.
 *
 * Return: Pointer to the value in the environment, or NULL if not found
 */
char *_getenv(char *name)
{
int i, len;
char *env_value;

if (name == NULL)
return (NULL);

len = _strlen((char *)name);

for (i = 0; environ[i] != NULL; i++)
{
if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
{
env_value = environ[i] + len + 1;
return (env_value);
}
}

return (NULL);
}
