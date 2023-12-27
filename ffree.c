#include "shell.h" 

/**
 * ffree - frees a string of other strings
 * @pp: a string of strings
 */
void ffree(char **pp)
{
char **a = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}
