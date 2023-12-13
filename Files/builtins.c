in betty style write code for that answers the following questions and fulfills the requirements.




List of allowed functions and system calls
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
General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)
Write a README with the description of your project
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker


Requirements
0. the code must follow betty style.
the header file should be named shell.h. 

1. Write a UNIX command line interpreter.

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


Compilation
Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Testing
Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$


List of functions files and functions to be written to answer the questions in accordance to the requirements.

File: shell.h
Functions:
- void handle_signal(int sig);
- void prompt(void);
- char *read_line(void);
- char **split_line(char *line);
- int execute(char **args);
- int launch(char **args);
- int builtin_cd(char **args);
- int builtin_help(char **args);
- int builtin_exit(char **args);
- int builtin_env(char **args);
- int is_builtin(char *command);
- int handle_builtin(char **args);
- void free_args(char **args);
- char *get_command_path(char *command);
- void environment_init(char **env);
- int set_env_var(char *name, char *value);
- int unset_env_var(char *name);
- int _atoi(char *str);
- void handle_end_of_file(char *line);

File: main.c
Functions:
- int main(int argc, char **argv, char **env);

File: prompt.c
Functions:
- void prompt(void);

File: read_line.c
Functions:
- char *read_line(void);

File: split_line.c
Functions:
- char **split_line(char *line);

File: execute.c
Functions:
- int execute(char **args);

File: launch.c
Functions:
- int launch(char **args);

File: builtins.c
Functions:
- int builtin_cd(char **args);
- int builtin_help(char **args);
- int builtin_exit(char **args);
- int builtin_env(char **args);
- int is_builtin(char *command);
- int handle_builtin(char **args);

File: env_functions.c
Functions:
- void environment_init(char **env);
- int set_env_var(char *name, char *value);
- int unset_env_var(char *name);

File: path_functions.c
Functions:
- char *get_command_path(char *command);

File: utility_functions.c
Functions:
- int _atoi(char *str);
- void handle_end_of_file(char *line);

File: signal_handler.c
Functions:
- void handle_signal(int sig);

File: AUTHORS
No functions, but a formatted list of contributors.

File: README.md
No functions, but contains project description.

Note: This list assumes that each file contains the functions related to its primary responsibility, and that the main.c file contains the entry point for the program.

