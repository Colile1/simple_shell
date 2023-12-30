#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: Structure of the parametre
 * @buf: buffer of character
 * @p: buffer position address
 *
 * Return: 1 if chain delimeter, else return 0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checks if more check must continue
 * @info: Structure of the parametre
 * @buf: buffer of character
 * @p: buffer position address
 * @i: buffer starting position
 * @len: buffer length
 *
 * Return: Nothing
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * change_alias - changes aliases to tokenized strings
 * @info: Structure of the parametre
 *
 * Return: 1 if replaced, else return 0
 */
int change_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = start_of_node(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * change_vars - replaces variables in the tokenized string
 * @info: Structure of the parametre
 *
 * Return: 1 if replaced, else return 0
 */
int change_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			change_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			change_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = start_of_node(info->env, &info->argv[i][1], '=');
		if (node)
		{
			change_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		change_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * change_string - replaces old string with a new one
 * @old: old string address
 * @new: new string
 *
 * Return: 1 if replaced, else return 0
 */
int change_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
