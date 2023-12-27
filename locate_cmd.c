#include "shell.h" 

/**
 * locate_cmd - Searches for a command within the PATH directories
 * @info: the structure containing parameters and returned information
 *
 * Return: None
 */
void locate_cmd(info_t *info)
{
char *path = NULL;
int i, k;

info->path = info->argv[0];

if (info->linecount_flag == 1)
{
info->line_count++;
info->linecount_flag = 0;
}

for (i = 0, k = 0; info->arg[i]; i++)
if (!is_delim(info->arg[i], " \t\n"))
k++;

if (!k)
return;

path = locate_path(info, _getenv(info, "PATH="), info->argv[0]);

if (path)
{
info->path = path;
fork_cmd(info);
}
else
{
if ((interactive(info) || _getenv(info, "PATH=") || info->argv[0][0] == '/')
&& is_executable(info, info->argv[0]))
fork_cmd(info);
else if (*(info->arg) != '\n')
{
info->status = 127;
print_error(info, "not found\n");
}
}
}