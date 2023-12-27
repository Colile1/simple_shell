#include "shell.h" 

/**
 * print_list_str - prints the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: length of modified list
 */
size_t print_list_str(const list_t *h)
{
size_t i = 0;

while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}
