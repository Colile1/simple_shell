#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @info: Struct with possible args.
 * @name: environment variable name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

while (node)
{
p = starts_with(node->str, name);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}
