#include "shell.h"

/**
 * _my_hist - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure of arguments that maintains constant function prototype
 *  Return: 0
 */
int _my_hist(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * uncreate_alias - creates an alias for a string
 * @info: structure of parameter
 * @str: the string alias
 *
 * Return: 0 on success, else return 1
 */
int uncreate_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, start_of_node(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * create_alias - creates an alias for a string
 * @info: structure of parameter
 * @str: the string alias
 *
 * Return: 0 on success, else return 1
 */
int create_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (uncreate_alias(info, str));

	uncreate_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: 0 on success, else return 1
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _my_alias - acts like the alias built_in (man alias)
 * @info: Structure with arguments to maintains constant function prototype.
 *  Return: 0
 */
int _my_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			create_alias(info, info->argv[i]);
		else
			print_alias(start_of_node(info->alias, info->argv[i], '='));
	}

	return (0);
}
