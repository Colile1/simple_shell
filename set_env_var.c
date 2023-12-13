#include "shell.h"

/**
 * set_env_var - sets an environment variable
 * @name: name of the environment variable
 * @value: value to set the variable to
 *
 * Return: 1 on success, or -1 on error
 */
int set_env_var(char *name, char *value)
{
int i;
char *variable;
size_t len;

if (!name || !value)
return (-1);

len = _strlen(name) + _strlen(value) + 2;
variable = malloc(len);
if (!variable)
return (-1);

_strcpy(variable, name);
_strcat(variable, "=");
_strcat(variable, value);

for (i = 0; environ[i]; i++)
{
if (_strncmp(environ[i], name, 
_strlen(name)) == 0 && environ[i][_strlen(name)] == '=')
{
free(environ[i]);
environ[i] = variable;
return (1);
}
}

environ = _realloc(environ, sizeof(char *) * (i + 2));
if (!environ)
{
free(variable);
return (-1);
}

environ[i] = variable;
environ[i + 1] = NULL;

return (1);
}
