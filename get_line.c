#include "main.h"

/**
 * re_lineptr - redefines the double pointer, lineptr used in get_line
 * @line_ptr: character array used to store an input string
 * @size: current size of lineptr array
 * @buffer: contains a string that is assigned to lineptr
 * @b: size of the buffer
 */

void re_lineptr(char **line_ptr, size_t *size, char *buffer, size_t b)
{
	char **lineptr = line_ptr;
	char *buf = buffer;
	size_t *new = size;
	size_t c = b;

	if (*lineptr == NULL)
	{
		if (c > 120)
			*new = c;
		else
			*new = 120;
		*lineptr = buf;
	}
	else if (*new < c)
	{
		if (c > 120)
			*new = c;
		else
			*new = 120;
		*lineptr = buf;
	}
	else
	{
		_strcpy(*lineptr, buf);
		free(buf);
	}
}

/**
 * get_line - a function that reads input from a stream.
 * @line_ptr: buffer that stores the input.
 * @size: size of lineptr
 * @stream: The stream where input is read from.
 *
 * Return: The number of bytes read.
 */

ssize_t get_line(char **line_ptr, size_t *size, FILE *stream)
{
	size_t *new = size;
	char **lineptr = line_ptr;
	static ssize_t input;
	ssize_t ret = 0;
	char c = 'x';
	char *buffer = NULL;
	int r = 0;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
			buffer = _realloc(buffer, 120, input + 1);
		buffer[input] = c, input++;
	}
	buffer[input] = '\n';
	re_lineptr(lineptr, new, buffer, input);
	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
