#include "main.h"

/**
 * free_mem - a function that frees a 2 dimensional array
 * @arr: a multidimensional array of integers
 * @height: array height
 *
 * Return: does not return
 */

void free_mem(char **arr, int height)
{
	height -= 1;

	if (arr != NULL && height != 0)
	{
		for (; height >= 0; height--)
		{
			free(arr[height]);
		}
		free(arr);
	}
}

/**
 * free_cmd - function that frees cmd envar
 *
 * @cmd: cmd struct
 * Return: does not return
 */
void free_cmd(cmd_t *cmd)
{
	int i;

	for (i = 0; cmd->envar[i]; i++)
		free(cmd->envar[i]);

	free(cmd->envar);
	free(cmd->pid);
}
