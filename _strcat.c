#include "shell.h"
#include <stdio.h>

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string to append to the destination
 *
 * Description: Appends the src string to the dest string,
 * overwriting the terminating null byte ('\0') at the end
 * of dest, and then adds a terminating null byte.
 *
 * Return: A pointer to the resulting string dest
 */

char *_strcat(char *dest, const char *src)
{
char *dest_end = dest;

while (*dest_end != '\0')
{
dest_end++;
}

while (*src != '\0')
{
*dest_end = *src;
dest_end++;
src++;
}

*dest_end = '\0';

return (dest);
}
