#include "shell.h"

/**
 * builtin_help - Displays help for a built-in command
 * @args: Array of arguments where the first argument is the command
 *    and the second is the built-in for which help is needed
 *
 * Return: Always returns 1 to continue executing
 */
int builtin_help(char **args)
{
char *help_messages[] = {
"cd: Change the directory.\n"
"Usage: cd [DIRECTORY]\n\n",
"exit: Exit the shell.\n"
"Usage: exit [STATUS]\n\n",
"env: Print the environment.\n"
"Usage: env\n\n",

NULL
};
char *builtin_str[] = {
"cd",
"exit",
"env",
NULL
};
int i;
if (args[1] == NULL)
{
for (i = 0; builtin_str[i] != NULL; i++)
{
write(STDOUT_FILENO, help_messages[i], strlen(help_messages[i]));
}
}
else
{
for (i = 0; builtin_str[i] != NULL; i++)
{
if (strcmp(args[1], builtin_str[i]) == 0)
{
write(STDOUT_FILENO, help_messages[i], strlen(help_messages[i]));
break;
}
}
if (builtin_str[i] == NULL)
{
write(STDOUT_FILENO, "No help available for this command.\n", 35);
}
}
return (1);
}
