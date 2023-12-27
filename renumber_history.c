
#include "shell.h" 

/**
 * renumber_history - renumbers the history linked list post changes
 * @info: Structure containing potential arguments
 *
 * Return: the new history count
 */
int renumber_history(info_t *info)
{
list_t *node = info->history;
int i = 0;

while (node)
{
node->num = i++;
node = node->next;
}
return (info->histcount = i);
}
