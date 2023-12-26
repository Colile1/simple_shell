#include "shell.h"
/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: signal number
 *
 * Return: nothing
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
