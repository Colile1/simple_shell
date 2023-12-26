#include "shell.h" 

/**
 * set_info - starts the info_t structure by setting
 * the appropriate fields
* @info_t: pointer to the info_t struct to initialize

 * @arg_v: argument vector containing command line arguments
 */
void set_info(info_t *info, char **arg_v)
{
int i = 0;

info->fname = arg_v[0];
if (info->arg)
{
info->argv = strtow(info->arg, " \t");
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = NULL;
}
}
for (i = 0; info->argv && info->argv[i]; i++);
info->argc = i;
replace_alias(info);
replace_vars(info);
}
}
