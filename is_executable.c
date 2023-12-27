#include "shell.h" 

/**
 * is_executable - checks if a file
 * @info: pointer to the information structure
 * @path: file path to executable file
 *
 * Return: 1 if the file is executable, else return 0
 */
int is_executable(info_t *info, char *path)
{
struct stat st;

(void)info;
if (!path || stat(path, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}
