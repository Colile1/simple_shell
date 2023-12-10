#include "shell.h"

/**
 * shell_execute - Executes the shell command
 * @input: The input command
 * @env: Null-terminated array of environment variables
 *
 * Return: Status code of the executed command, or an error code
 */
int shell_execute(char *input, char **env)
{
    char **args;
    char *cmd_path;
    int status;

    /* Parse the input to get the command and arguments*/
    args = parse(input, env);
    if (args == NULL || args[0] == NULL) {
        // Handling empty commands or parsing failure
        return 1;
    }

    // Find the path of the command
    cmd_path = find_path(args[0], env);
    if (cmd_path != NULL) {
        // Run the command if the path is found
        status = run_command(cmd_path, args, env);
        free(cmd_path); // Remember to free the allocated path
    } else {
        // If the command path is not found, try to execute it directly (maybe it's a built-in or alias)
        status = execute(args, env);
    }

    // Free the arguments array
    for (int i = 0; args[i] != NULL; i++) {
        free(args[i]);
    }
    free(args);

    return status;
}
