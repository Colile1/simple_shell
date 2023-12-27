#include "shell.h" 

/**
 * locate_path - Locates the full path of a command if present in the PATH environment variable.
 * @info: Pointer to the info structure which may contain other relevant information.
 * @pathstr: The string containing the PATH environment variable.
 * @cmd: The command for which to find the full path.
 *
 * Description: This function searches for the full path of the specified command by looking
 * through each directory listed in the PATH environment variable. If the command
 * starts with "./", it checks whether the command is executable in the current
 * directory. Otherwise, it concatenates the command with each directory in PATH
 * until it finds an executable match. The search ends when an executable path
 * is found or when all directories have been checked.
 *
 * Return: A pointer to a string containing the full path of the command if found,
 * or NULL if the command cannot be located or is not executable.
 */
char *locate_path(info_t *info, char *pathstr, char *cmd)
{
int index = 0, current_position = 0;
char *full_path;

if (!pathstr)
{
return (NULL);
}

if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_executable(info, cmd))
{
return (cmd);
}
}

while (1)
{
if (!pathstr[index] || pathstr[index] == ':')
{
full_path = copy_substring(pathstr, current_position, index);
if (!*full_path)
{
_strcat(full_path, cmd);
}
else
{
_strcat(full_path, "/");
_strcat(full_path, cmd);
}

if (is_executable(info, full_path))
{
return (full_path);
}

free(full_path);

if (!pathstr[index])
{
break;
}
current_position = ++index;
}
else
{
index++;
}
}
return (NULL);
}
