#include "shell.h"

/**
 * builtin - This function handles the execution of built-in shell commands.
 * @cmd: The command to execute.
 * @env: The environment variables.
 * @status: The last status code.
 *
 * Return: The status code of the executed command or built-in function.
 */
int builtin(char *cmd, char **env, int *status)
{
    if (_strcmp(cmd, "exit") == 0)
    {
        builtin_exit(*status);
        return (*status);
    }
    else if (_strcmp(cmd, "env") == 0)
    {
        *status = builtin_env(env);
        return (*status);
    }
    else
    {
        /*If the command is not a built-in, return a special code to indicate this
        i.e. define a constant for this, like `#define NOT_BUILTIN -1`*/
        return (NOT_BUILTIN);
    }
}
 