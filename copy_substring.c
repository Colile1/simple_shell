#include "shell.h" 

/**
 * copy_substring - copies a substring from pathstr into a new buffer
 * @pathstr: the original string
 * @start: index to start copying from
 * @stop: index to stop copying
 *
 * Return: pointer to the new buffer containing the substring
 */

char *copy_substring(char *pathstr, int start, int stop)
{
static char buf[1024];
int i = 0, k = 0;

for (k = 0, i = start; i < stop; i++)
if (pathstr[i] != ':')
buf[k++] = pathstr[i];
buf[k] = 0;
return (buf);
}
