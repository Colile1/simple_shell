#include "shell.h"

/**
 * handle_signal - Handles the signal
 * @sig: The signal to handle
 */
void handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
