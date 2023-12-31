#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure with arguments to maintains constant function prototype.
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure with potential arguments
 * @name: environment variablable name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _myset_enviro - initiate a new environment variable,
 *             or change an existing one
 * @info: Structure of arguments that maintains constant function prototype
 *  Return: 0
 */
int _myset_enviro(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_set_enviro(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunset_enviro - Remove an environment variable
 * @info: Structure of arguments that maintains constant function prototype
 *  Return: 0
 */
int _myunset_enviro(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unset_enviro(info, info->argv[i]);

	return (0);
}

/**
 * fill_up_enviro_list - populates env linked list
 * @info: Structure with arguments to maintains constant function prototype.
 * Return: 0
 */
int fill_up_enviro_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
