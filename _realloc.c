#include "shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes, of the new memory block
 *
 * Description: reallocates a memory block using malloc and free
 * If new_size == old_size do not do anything and return ptr.
 * If new_size == 0 and ptr is not NULL, then the call is equivalent
 * to free(ptr). Return NULL.
 * If ptr is NULL, then the call is equivalent to malloc(new_size).
 *
 * Return: pointer to the newly allocated memory block, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *new_ptr;

if (new_size == old_size)
return (ptr);

if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}

new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);

if (ptr != NULL)
{
size_t copy_size = old_size < new_size ? old_size : new_size;
memcpy(new_ptr, ptr, copy_size);
free(ptr);
}

return (new_ptr);
}
