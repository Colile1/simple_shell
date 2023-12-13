#include "shell.h"

/**
 * run_command - Runs commands by execve after forking
 * @cmd: Command to run
 * @args: Null-terminated array of arguments (including program)
 * @env: Null-terminated array of environment variables
 *
 * Return: Status code of the executed command
 */
int run_command(char *cmd, char **args, char **env)
{
    pid_t pid;
    int status;

    if (cmd == NULL || args == NULL)
    {
        return (1);
    }

    if (access(cmd, X_OK) != 0)
    {
        perror("Command not found or not executable");
        return (1);
    }

    pid = fork();
    if (pid == 0) {

        if (execve(cmd, args, env) == -1) 
        {
            perror("execve error");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("fork error");
        return (1);
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (WEXITSTATUS(status));
}
