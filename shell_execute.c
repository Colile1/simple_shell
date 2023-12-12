#include "shell.h"

/**
 * shell_execute - Executes the shell command
 * @input: The input command
 * @env: Null-terminated array of environment variables
 *
 * Return: Status code of the executed command, or an error code
 */
int shell_execute(char *input, char **env)
{
char **args;
char *cmd_path;
int status;

args = parse(input, env);
if (args == NULL || args[0] == NULL)
{
return (1);
}

cmd_path = find_path(args[0], env);
if (cmd_path != NULL)
{
status = run_command(cmd_path, args, env);
free(cmd_path);
}
else
{
status = execute(args, env);
}

for (int i = 0; args[i] != NULL; i++)
{
free(args[i]);
}
free(args);

return (status);
}
