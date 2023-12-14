#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - creates a duplicate of the string str.
 * @str: the string to duplicate
 * 
 * Return: a pointer to the duplicated string or NULL if insufficient memory was available
 */
char *_strdup(const char *str)
{
char *duplicate;
size_t len;

if (!str)
return NULL;

len = strlen(str) + 1;
duplicate = malloc(len);

if (duplicate)
memcpy(duplicate, str, len);

return (duplicate);
}
