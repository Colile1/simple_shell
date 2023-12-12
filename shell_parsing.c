#include "shell.h"

/**
 * shell_parsing - Parses a command line input and executes the command.
 * @input: Command line input string
 * @env: Null-terminated array of environment variables
 *
 * Description: This function uses tokenize to split the input into tokens and
 *              parse to get the executable and its arguments. It then
 *              executes the command using execve system call. If the command
 *              is not found, it prints an error message.
 * Return: Status of the execution or -1 on failure.
 */
int shell_parsing(char *input, char **env)
{
    char **tokens;
    char **args;
    pid_t pid;
    int status;

    if (input == NULL || env == NULL)
    {
        perror("Invalid argument");
        return (-1);
    }

    tokens = tokenize(input);
    if (tokens == NULL)
    {
        perror("Tokenization error");
        return (-1);
    }

    args = parse(input, env);
    if (args == NULL)
    {
        free(tokens); /* Free tokens if parsing fails */
        perror("Parsing error");
        return (-1);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("Forking error");
        free(tokens);
        free(args);
        return (-1);
    }
    if (pid == 0)
    {
        /* Child process */
        if (execve(args[0], args, env) == -1)
        {
            perror("Execution error");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        waitpid(pid, &status, 0);
        free(tokens);
        free(args);
        return (WEXITSTATUS(status));
    }
    /* This part is unreachable, but added for clarity */
    return (-1);
}

