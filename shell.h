#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/* for input/output buffers */
#define READ_BUF_SIZE 1024  
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


/* values for cmd_buf_type, indicating command chaining type */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3


/* convert text to lowercase */
#define CONVERT_LOWERCASE 1

/* convert text to unsigned */
#define CONVERT_UNSIGNED 2

/* use system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;


/**
 * struct liststr - singly linked list node 
 * @num: integer field  
 * @str: string field
 * @next: pointer to next node
*/

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains information to pass into a function,
 *		allowing uniform prototype for function pointer struct.
 * @alias: the alias node
 * @arg: a string generated from getline containing arguments
 * @argc: the argument count
 * @argv: an array of strings generated from arg
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @env: linked list local copy of environ
 * @env_changed: on if environ was changed
 * @environ: custom modified copy of environ from LL env
 * @err_num: the error code for exit()s
 * @fname: the program filename
 * @histcount: the history line number count
 * @history: the history node
 * @line_count: the error count
 * @linecount_flag: if on count this line of input
 * @path: a string path for the current command
 * @readfd: the fd from which to read line input
 * @status: the return status of the last exec'd command
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;

	list_t *env;
	list_t *history;
	list_t *alias;

	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * builtin - contains a builtin command string and related function
 * @type: the builtin command string
 * @func: the function for the builtin command
 * description - struct is a container for builtin command 
 */

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int shell_loop(info_t *, char **);
int find_builtin_cmd(info_t *);
void locate_cmd(info_t *);
void fork_cmd(info_t *);

int is_executable(info_t *, char *);
char *locate_path(info_t *, char *, char *);
char *copy_substring(char *, int, int);


void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

int _myhistory(info_t *);
int _myalias(info_t *);
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

char **strtow(char *, char *);
char **strtow2(char *, char);

void *_realloc(void *, unsigned int, unsigned int);
char *_memset(char *, char, unsigned int);
void ffree(char **);

ssize_t input_buf(info_t *, char **, size_t *);
int bfree(void **);

int _isalpha(int);
int is_delim(char, char *);
int interactive(info_t *);
int _atoi(char *);

int _erratoi(char *);
char *convert_number(long int, int, int);
void print_error(info_t *, char *);
int print_d(int, int);
void remove_comments(char *);


ssize_t read_buf(info_t *, char *, size_t *);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

char *get_history_file(info_t *info);
int read_history(info_t *info);
int store_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

char **list_to_strings(list_t *);
list_t *node_starts_with(list_t *, char *, char);
size_t list_len(const list_t *);
size_t print_list(const list_t *);
ssize_t get_node_index(list_t *, list_t *);

int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
