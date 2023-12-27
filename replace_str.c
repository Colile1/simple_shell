
#include "shell.h" 

/**
 * replace_string - replaces old string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if successful else return 0.
 */
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
