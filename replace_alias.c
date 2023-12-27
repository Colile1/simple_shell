
#include "shell.h" 

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the  parameter used to access information stored in 
 * the info_t structure
 *
 * Return: 1 if replaced else return 0
 */
int replace_alias(info_t *info)
{
int i;
list_t *node;
char *p;

for (i = 0; i < 10; i++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
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
