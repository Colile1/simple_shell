#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: string to print
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes A charactr c to stderr
 * @c: A charactr to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putf_dscr - writes A charactr c to given f_dscr
 * @c: A charactr to print
 * @f_dscr: File descrptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putf_dscr(char c, int f_dscr)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(f_dscr, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsf_dscr - prints an input string
 * @str: string to print
 * @f_dscr: File descrptor to write to
 *
 * Return: the number of chars put
 */
int _putsf_dscr(char *str, int f_dscr)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putf_dscr(*str++, f_dscr);
	}
	return (i);
}
