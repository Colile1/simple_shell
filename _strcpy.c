#include "shell.h" 

/**
 * _strcpy - makes a copy of a string
 * @dest: destination
 * @src: source
 *
 * Return: pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == src || src == 0)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}
