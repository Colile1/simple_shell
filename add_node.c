#include "shell.h" 

/**
 * add_node - adds a node to the start of a list
 * @head: address of a pointer to the head node
 * @str: string field of node
 * @num: the index of the node used by history
 *
 * Return: size of modified list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
list_t *new_head;

if (!head)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->num = num;
if (str)
{
new_head->str = _strdup(str);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}
new_head->next = *head;
*head = new_head;
return (new_head);
}
