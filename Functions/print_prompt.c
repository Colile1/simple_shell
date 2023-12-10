#include "shell.h"

/**
 * print_prompt - Prints prompt to stdout
 */
void print_prompt(void)
{
    char *prompt = "$ ";
    _puts(prompt);
    fflush(stdout);
}
