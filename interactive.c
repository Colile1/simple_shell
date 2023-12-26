#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: pointer to the info_t struct to initialize
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
