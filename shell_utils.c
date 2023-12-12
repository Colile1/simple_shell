#include "shell.h"

/**
 * shell_utils - a collection of utility functions for the shell
 *
 * Description: Implements various utility functions that will be
 * used throughout the shell program. It utilizes safe and efficient
 * string manipulation functions.
 */

/**
 * strdup_wrapper - a wrapper for the _strdup function
 * @str: the string to duplicate
 *
 * Return: a pointer to the duplicated string or 
 * NULL if insufficient memory was available
 */
char *strdup_wrapper(const char *str)
{
    return (_strdup(str));
}

/**
 * strtok_wrapper - a wrapper for the _strtok function
 * @str: The string to tokenize.
 * @delim: The delimiter string.
 *
 * Return: A pointer to the next token, or NULL if there are no more tokens.
 */
char *strtok_wrapper(char *str, const char *delim)
{
    return (_strtok(str, delim));
}

/**
 * strlen_wrapper - a wrapper for the _strlen function
 * @s: string to calculate the length of
 *
 * Return: the number of characters in the string
 */
size_t strlen_wrapper(const char *s)
{
    return (_strlen(s));
}
