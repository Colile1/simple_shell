#include "shell.h"

/**
 * builtin_exit - Exits the shell
 * @status: The exit status
 *
 * Return: Does not return
 */
void builtin_exit(int status)
{
    exit(status);
}
