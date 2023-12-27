
#include "shell.h" 

/**
 * check_chain - checks if chaining can continue
 * @info: parameter used to access information stored
 * in the info_t structure
 * @buf: buffer
 * @p: address of current position in the buffer
 * @i: starting position in the buffer
 * @len: length of the buffer
 *
 * Return: Void
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
