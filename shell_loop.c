#include "shell.h"

/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @arg_v: the argument vector from main()
 *
 * Return: 0 on success, else return 1, or error code
 */
int hsh(info_t *info, char **arg_v)
{
	ssize_t r = 0;
	int built_in_ret = 0;

	while (r != -1 && built_in_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, arg_v);
			built_in_ret = find_built_in(info);
			if (built_in_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_hist(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (built_in_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (built_in_ret);
}

/**
 * find_built_in - finds a built_in command
 * @info: the parameter & return info struct
 *
 * Return: -1 if built_in not found,
 *			0 if built_in executed successfully,
 *			1 if built_in found but not successful,
 *			-2 if built_in signals exit()
 */
int find_built_in(info_t *info)
{
	int i, built_in_ret = -1;
	built_in_table built_intbl[] = {
		{"exit", _my_exit},
		{"env", _myenv},
		{"help", _my_help},
		{"history", _my_hist},
		{"set_enviro", _myset_enviro},
		{"unset_enviro", _myunset_enviro},
		{"cd", _change_cd},
		{"alias", _my_alias},
		{NULL, NULL}
	};

	for (i = 0; built_intbl[i].type; i++)
		if (_strcmp(info->argv[0], built_intbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = built_intbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: Nothing
 */
void find_cmd(info_t *info)
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

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: Nothing
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_enviro(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
