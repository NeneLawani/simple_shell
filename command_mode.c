#include "main.h"

/**
 * command_mode - function that sets the mode of execution
 *
 * @buffer: buffer which contains arguments
 * @cmd: the command struct
 * Return: does not return
 */

void command_mode(char *buffer, cmd_t *cmd)
{
	if (!buffer[0])
		exit(EXIT_FAILURE);

	cmd->mode = EXEC;
}
