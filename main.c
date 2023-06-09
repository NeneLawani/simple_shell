#include "main.h"

/**
 * main - Entry point
 *
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: int value
 */

int main(int ac, char **av)
{
	cmd_t cmd;
	(void) ac;

	signal(SIGINT, handl_sigint);
	/*open_console();*/
	init_var(&cmd, av);
	rep_loop(&cmd);
	free_cmd(&cmd);
	return (cmd.status);
}

/**
 * rep_loop - read, evaluate and print shell loop
 * @cmd: data relevant (av, input, args)
 *
 * Return: does not return
 */

void rep_loop(cmd_t *cmd)
{
	int loop;
	int i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		input =  read_input(1, &i_eof);
		if (i_eof != -1)
		{
			input = handl_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(cmd, input) == 1)
			{
				cmd->status = 2;
				free(input);
				continue;
			}

			input = analyze_input(input, cmd);
			loop = apply_seperators(cmd, input);
			cmd->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
