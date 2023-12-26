#include "shell.h"

/**
 * is_delim - checks if character is a delimeter
 * @c: the chararacter to check
 * @delim: the delimeter string
 * Return: 1 if true, else return 0
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}
