#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * _strtok - Tokenizes a string into tokens.
 * @str: The string to tokenize.
 * @delim: The delimiter string.
 *
 * Return: A pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
static char *next_token;
char *current_token;

if (str != NULL)
{
next_token = str;
}

if (next_token == NULL)
{
return (NULL);
}

next_token += strspn(next_token, delim);
if (*next_token == '\0')
{
return (NULL);
}

current_token = next_token;
next_token = strpbrk(current_token, delim);
if (next_token != NULL)
{
*next_token = '\0';
next_token++;
}

return (current_token);
}
