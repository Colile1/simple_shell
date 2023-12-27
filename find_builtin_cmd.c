#include "shell.h" 

/**
 * find_builtin_cmd - locates a built-in command
 * @info: the parameter and return info structure
 *
 * Return: -1 if built-in not found,
 *			0 if built-in executed successfully,
 *			1 if built-in found but not successful,
 *			-2 if built-in signals exit()
 */

int find_builtin_cmd(info_t *info)
{
int i, built_in_ret = -1;
builtin_table builtintable[] = {
{"alias", _myalias},
{"cd", _mycd},
{"env", _myenv},
{"exit", _myexit},
{"help", _myhelp},
{"history", _myhistory},
{"setenv", _mysetenv},
{"unsetenv", _myunsetenv},
{NULL, NULL}};

for (i = 0; i < (int)(sizeof(builtintable) / sizeof(builtin_table)); i++)
{
if (_strcmp(info->argv[0], builtintable[i].type) == 0)
{
info->line_count++;
built_in_ret = builtintable[i].func(info);
break;
}
}

return (built_in_ret);
}
