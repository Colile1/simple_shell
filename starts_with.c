#include "shell.h" 

/**
 * starts_with - checks if word starts with phrase
 * @phrase: string to search
 * @word: the substring to find
 *
 * Return: address of next char of phrase or NULL
 */
char *starts_with(const char *phrase, const char *word)
{
while (*word)
if (*word++ != *phrase++)
return (NULL);
return ((char *)phrase);
}
