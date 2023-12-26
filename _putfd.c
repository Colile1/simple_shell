#include "shell.h" 

/**
 * _putfd - writes the character c to given filedescriptor
 * @c: The character to print
 * @fd: filedescriptor to be written on
 *
 * Return: 1 if success
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
