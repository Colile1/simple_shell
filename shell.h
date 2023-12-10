#ifndef SHELL_H
#define SHELL_H

#include <unistd.h> /* chdir, close, execve, fork, getpid, isatty, access, _exit */
#include <sys/types.h>  /* pid_t, stat, lstat, fstat, opendir, closedir, readdir */
#include <sys/stat.h>   /* stat, lstat, fstat */
#include <sys/wait.h>   /* wait, waitpid, wait3, wait4 */
#include <signal.h>     /* signal, kill */
#include <stdio.h>      /* getline, perror, fflush */
#include <stdlib.h>     /* exit, free, malloc, realloc */
#include <fcntl.h>      /* open */
#include <dirent.h>     /* opendir, closedir, readdir */
#include <string.h>     /* strtok */

/* Function prototypes */
int _putchar(char c);
int _puts(char *str);
char *_strdup(const char *str);
size_t _strlen(const char *s);
char *_strtok(char *str, const char *delim);
int builtin_env(char **env);
void builtin_exit(int status);
int execute(char **args, char **env);
char *find_path(char *cmd, char **env);
char **parse(char *input, char **env);
void print_prompt(void);
char *read_input(void);
int run_command(char *cmd, char **args, char **env);
char **tokenize(char *input);

#endif
