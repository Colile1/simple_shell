#include "shell.h"

/**
 * main - Entry point for the shell
 * @argc: Number of command line arguments
 * @argv: List of command line arguments
 * @envp: Array of environment variables
 *
 * Return: Status code
 */
int main(int argc, char **argv, char **envp)
{
    char *input;
    int status = 0;

    (void)argc;
    (void)argv;

    signal(SIGINT, SIG_IGN);

    while (1)
    {
        print_prompt();
        input = read_input();
        if (input == NULL || _strcmp(input, "exit") == 0)
        {
            free(input);
            builtin_exit(status);
        }

        status = shell_execute(input, envp);

        free(input);
    }

    /* Code should not reach this point */
    return (EXIT_FAILURE);
}
