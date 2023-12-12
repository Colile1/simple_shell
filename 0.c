in betty style write code for the shell.c. Use 

the already written functions:

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


Requirements
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ", ', ', `, \, *, &, #
be able to move the cursor
handle commands with arguments
execve will be the core part of your Shell, do not forget to pass the environ to it

2. Simple shell 0.1 +
Handle command lines with arguments

3. Simple shell 0.2 +
Handle the PATH
fork must not be called if the command does not exist

4. Simple shell 0.3 +
Implement the exit built-in, that exits the shell
Usage: exit
You do not have to handle any argument to the built-in exit

5. Simple shell 0.4 +
Implement the env built-in, that prints the current environment

ADDITIONAL SHELL REQUIREMENTS

6. Simple shell 0.1 +
Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline

7. Simple shell 0.2 +
You are not allowed to use strtok

8. Simple shell 0.4 +
handle arguments for the built-in exit
Usage: exit status, where status is an integer used to exit the shell

9. Simple shell 1.0 +
Implement the setenv and unsetenv builtin commands

setenv
Initialize a new environment variable, or modify an existing one
Command syntax: setenv VARIABLE VALUE
Should print something on stderr on failure
unsetenv
Remove an environment variable
Command syntax: unsetenv VARIABLE
Should print something on stderr on failure

10. Implement the builtin command cd:
Changes the current directory of the process.
Command syntax: cd [DIRECTORY]
If no argument is given to cd the command must be interpreted like cd $HOME
You have to handle the command cd -
You have to update the environment variable PWD when you change directory
man chdir, man getcwd

11. Simple shell 1.0 +
Handle the commands separator ;

12. Simple shell 1.0 +
Handle the && and || shell logical operators

13. Simple shell 1.0 +
Implement the alias builtin command
Usage: alias [name[='value'] ...]
alias: Prints a list of all aliases, one per line, in the form name='value'
alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value

14. Simple shell 1.0 +
Handle variables replacement
Handle the $? variable
Handle the $$ variable

15. Simple shell 1.0 +
Handle comments (#)

Simple shell 1.0 +
Handle redirections

16. Simple shell 1.0 +
Usage: simple_shell [filename]
Your shell can take a file as a command line argument
The file contains all the commands that your shell should run before exiting
The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from stdin

