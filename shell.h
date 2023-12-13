#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

/* Function Prototypes for signal handling and prompt */
void handle_signal(int sig);
void prompt(void);

/* Function Prototypes for command processing */
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
int launch(char **args);

/* Function Prototypes for built-in shell commands */
int builtin_cd(char **args);
int builtin_help(char **args);
int builtin_exit(char **args);
int builtin_env(char **args);
int is_builtin(char *command);
int handle_builtin(char **args);

/* Function Prototypes for environment variables */
void environment_init(char **env);
int set_env_var(char *name, char *value);
int unset_env_var(char *name);

/* Function Prototypes for utility functions */
int _atoi(char *str);
void handle_end_of_file(char *line);
char *get_command_path(char *command);
void free_args(char **args);

#endif /* SHELL_H */
