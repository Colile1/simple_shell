#include "shell.h"

/**
 * _puts - prints a string to stdout
 * @str: the string to print
 * Return: the number of characters printed
 */
int _puts(char *str)
{
int i = 0;
int count = 0;

while (str[i] != '\0')
{
count += _putchar(str[i]);
i++;
}
return (count);
}
