#include "shell.h"

/**
 * builtin_cd - Changes the current directory of the process
 * @args: Pointer to array of strings where the first string is "cd"
 *        and the second string is the directory to change to
 *
 * Return: 1 on success, or a negative value on error
 */
int builtin_cd(char **args)
{
char *new_dir;
char cwd[1024];

if (args[1] == NULL || strcmp(args[1], "~") == 0)
{
new_dir = getenv("HOME");
if (new_dir == NULL)
{
perror("builtin_cd: getenv");
return (-1);
}
}
else if (strcmp(args[1], "-") == 0)
{
new_dir = getenv("OLDPWD");
if (new_dir == NULL)
{
perror("builtin_cd: getenv");
return (-1);
}
printf("%s\n", new_dir);
}
else
{
new_dir = args[1];
}

if (chdir(new_dir) != 0)
{
perror("builtin_cd: chdir");
return (-1);
}

if (getcwd(cwd, sizeof(cwd)) == NULL)
{
perror("builtin_cd: getcwd");
return (-1);
}

if (set_env_var("PWD", cwd) != 0)
{
perror("builtin_cd: set_env_var PWD");
return (-1);
}

return (1);
}
