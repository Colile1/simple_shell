#include "shell.h"
/**
 * _realloc - reallocates memory block
 * @ptr: pointer to previous malloc block
 * @old_size: byte size of old block
 * @new_size: byte size of new block
 *
 * Return: pointer p
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
