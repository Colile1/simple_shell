#include "shell.h" 

/**
 * _strcat - combines two strings
 * @dest: destination buffer
 * @src: source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
