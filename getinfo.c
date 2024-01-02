#include "shell.h"

/**
 * clear_info - initiates info_t struct
 * @info: address of the structure
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - initiates info_t struct
 * @info: address of the structure
 * @arg_v: argument vector
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
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		change_alias(info);
		change_vars(info);
	}
}

/**
 * free_info - frees info_t struct fields
 * @info: address of the structure
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readf_dscr > 2)
			close(info->readf_dscr);
		_putchar(BUF_FLUSH);
	}
}
