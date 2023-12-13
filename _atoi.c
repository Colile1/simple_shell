#include "shell.h"

/**
 * _atoi - convert a string to an integer.
 * @str: string to convert
 *
 * Return: the integer value of the string
 */

int _atoi(char *str)
{
int sign = 1;
unsigned int num = 0;

if (str == NULL)
return (0);

while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
str++;

if (*str == '-')
{
sign = -1;
str++;
}
else if (*str == '+')
{
str++;
}

while (*str >= '0' && *str <= '9')
{
num = num * 10 + (*str - '0');
str++;
}

return (num *sign);
}
