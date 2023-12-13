#include "shell.h"

/**
 * free_args - frees a list of arguments
 * @args: pointer to the array of arguments
 */
void free_args(char **args)
{
int i;

if (args == NULL)
return;

for (i = 0; args[i] != NULL; i++)
free(args[i]);

free(args);
}
