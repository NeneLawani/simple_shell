#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * open_console - a function that opens the console
 *
 * Return: does not return
 */

void open_console(void)
{
	int fd;

	while ((fd = open("/dev/console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break;
		}
	}
}

/**
 * prompt - writes the shell prompt to standard input
 *
 * @status: determines whether or not the shell is interactive
 * Return: nothing
 */

void prompt(int status)
{
	if (status)
		write(STDIN_FILENO, "$$ ", 3);
}

/**
 * t_error - a function that handles error
 *
 * @s: the error message
 * Return: does not return
 */

void t_error(char *s)
{
	write(STDERR_FILENO, s, _strlen(s));
}

/**
 * _fork - creating the child process
 *
 * Return: the process ID is returned
 */

int _fork(void)
{
	pid_t id = fork();

	if (id < 0)
	{
		t_error("Fork failed\n");
		return (1);
	}
	return (id);
}

/**
 * handl_sigint - a function that handle signals
 * @sig: the signal parameter
 * Return: does not return
 */

void handl_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "<saMosC/> SIGINT\n", 18);
}

