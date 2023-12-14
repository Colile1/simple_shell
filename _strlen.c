#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: String to count
 *
 * Return: String length
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
		count++;

	return (count);
}
