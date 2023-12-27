#include "shell.h" 

/**
 * fork_cmd - forks a process to run command
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
pid_t child_pid;

child_pid = fork();
if (child_pid == -1)
{
perror("Fork error");
return;
}

if (child_pid == 0)
{
if (execve(info->path, info->argv, environ) == -1)
{
perror("Execve error");
exit(1);
}
}
else
{
int status;
waitpid(child_pid, &status, 0);

if (WIFEXITED(status))
{
info->status = WEXITSTATUS(status);
}
}
}
