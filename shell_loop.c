#include "shell.h" 

/**
 * shell_loop - runs the main shell loop
 * @info: info struct for parameters and return values
 * @arg_v: argument vector from main()
 *
 * Returnclear: 0 if successful, 1 if error, or error code
 */

int shell_loop(info_t *info, char **arg_v)
{
ssize_t r = 0;
int builtin_ret = 0;

while (1)
{
clear_info(info);
if (interactive(info))
_puts("$ ");
_eputchar(BUF_FLUSH);
r = get_input(info);
if (r == -1)
{
if (interactive(info))
_putchar('\n');
break;
}

set_info(info, arg_v);
builtin_ret = find_builtin_cmd(info);
if (builtin_ret == -2)
break;
if (builtin_ret == -1)
locate_cmd(info);

free_info(info, 0);
}
store_history(info);
free_info(info, 1);

if (!interactive(info) && info->status)
exit(info->status);
if (builtin_ret == -2 && info->err_num != -1)
exit(info->err_num);

return (builtin_ret);
}
