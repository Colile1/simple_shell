#include "shell.h"

/**
 * shell_input - Handles the input for the shell
 *
 * Return: Pointer to the input string, or NULL on failure or if EOF is reached
 */
char *shell_input(void)
{
print_prompt();
return (read_input());
}
