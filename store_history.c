#include "shell.h" 

/**
 * store_history - writes history to an existing 
 *                  file or creates a new if file DNE 
 * @info: used to access information stored in 
 *          the info_t structure
 *
 * Return: 1 on success, else return -1
 */
int store_history(info_t *info)
{
ssize_t fd;
char *filename = get_history_file(info);
list_t *node = NULL;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fd == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, fd);
_putfd('\n', fd);
}
_putfd(BUF_FLUSH, fd);
close(fd);
return (1);
}
