#include "shell.h"

/**
 * builtin_env - Prints the current environment variables
 * @env: The environment variables array
 *
 * Return: Always 0 on success
 */
int builtin_env(char **env)
{
    int i = 0;

    while (env[i])
    {
        _puts(env[i]);
        _putchar('\n');
        i++;
    }
    return (0);
}
