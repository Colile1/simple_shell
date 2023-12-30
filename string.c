#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if sub_strng starts with src_strng
 * @src_strng: string to search
 * @sub_strng: the substring to find
 *
 * Return: address of next char of src_strng or NULL
 */
char *starts_with(const char *src_strng, const char *sub_strng)
{
while (*sub_strng)
if (*sub_strng++ != *src_strng++)
return (NULL);
return ((char *)src_strng);
}
/**
 * _strcat - combines two strings
 * @dest: the destination buffer
 * @src: source buffer
 *
 * Return: pointer towards destination buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
