#include "main.h"

/**
 * runcmd - a function that runs the inputed commands
 *
 * @dir: directory of the command to be executed
 * @input: string inputted by user
 * @cmd: the command struct
 * Return: 1 upon success and 0 upon failure
 */

void runcmd(char *dir, char **input, cmd_t *cmd)
{
	if (input[0] == NULL)
		exit(EXIT_FAILURE);

	switch (cmd->mode)
	{
		case EXEC:
			if (execve(dir, input, cmd->envar) < 0)
				t_error("No such file or directory\n");
			break;
	}

	exit(EXIT_SUCCESS);
}
