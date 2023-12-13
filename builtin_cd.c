#include "shell.h"

/**
 * change_directory - Changes the current working directory
 * @dir: Pointer to the directory path to change to
 *
 * Return: 1 on success, or a negative value on error
 */
static int change_directory(char *dir)
{
char cwd[1024];

if (chdir(dir) != 0)
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

/**
 * get_target_directory - Determines the target directory from the arguments
 * @args: Pointer to array of strings where the first string is "cd"
 *and the second string is the directory to change to
 *
 * Return: Target directory on success, or NULL on failure
 */
static char *get_target_directory(char **args)
{
if (args[1] == NULL || strcmp(args[1], "~") == 0)
{
return (getenv("HOME"));
}
else if (strcmp(args[1], "-") == 0)
{
char *oldpwd = getenv("OLDPWD");
if (oldpwd)
{
printf("%s\n", oldpwd);
}
return (oldpwd);
}
else
{
return (args[1]);
}
}
/**
 * builtin_cd - changes the current directory of the process
 * @args: array of arguments where args[0] is "cd"
 * and args[1] is the directory to change to
 *
 * Return: 1 on success, -1 on failure
 */
int builtin_cd(char **args)
{
char *new_dir = get_target_directory(args);
if (new_dir == NULL)
{
perror("builtin_cd: getenv");
return (-1);
}
return (change_directory(new_dir));
}
