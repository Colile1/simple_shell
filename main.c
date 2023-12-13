#include "shell.h"

/**
 * main - Entry point for the simple shell program
 * @argc: The count of arguments supplied to the program
 * @argv: An array of pointers to the arguments
 * @env: An array of pointers to the environment variables
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv, char **env)
{
char *line = NULL;
char **args = NULL;
int status = 1;

environment_init(env);
signal(SIGINT, handle_signal);

do {
prompt();
line = read_line();
if (line == NULL)
handle_end_of_file(line);

args = split_line(line);
if (args == NULL)
{
free(line);
continue;
}

if (is_builtin(args[0]))
status = handle_builtin(args);
else
status = launch(args);

free_args(args);
free(line);
}
while (status);

return (EXIT_SUCCESS);
}

