#include "main.h"

/**
 * read_input - reads the string input of user
 *
 * @num: value of getline is returned
 * @status: determines whether or not the shell is interactive
 * Return: inputted string is returned
 */
char *read_input(int status, int *num)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	prompt(status);
	*num = getline(&buffer, &bufsize, stdin);

	return (buffer);
}
