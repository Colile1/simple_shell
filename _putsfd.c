#include "shell.h" 

/**
 *_putsfd - prints an input string on filedescriptor 
 * @str: the string to be printed
 * @fd: the filedescriptor that is going to be written on 
 *
 * Return: the number of characters put
 */
int _putsfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}
