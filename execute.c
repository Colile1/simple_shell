#include "shell.h"

/**
 * execute - Executes a command in a child process
 * @args: Null-terminated array of arguments (including program)
 * @env: Null-terminated array of environment variables
 * 
 * Return: Status code of the executed command
 */
int execute(char **args, char **env)
{
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        if (execve(args[0], args, env) == -1) {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {

        perror("Error");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (WEXITSTATUS(status));
}
