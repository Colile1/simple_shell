in betty style write code for the shell.c 
use the already written functions:

int _putchar(char c);
int _puts(char *str);
int _strcmp(char *s1, char *s2);
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

int builtin(char *cmd, char **env, int *status);
int shell_execute(char *input, char **env);
char *shell_input(void);
int shell_parsing(char *input, char **env);

/*main function*/
int main(int argc, char **argv, char **envp);


List of other allowed functions and system calls
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)