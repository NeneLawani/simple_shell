#include "main.h"

/**
 * _strlen - determines the length of string
 * @s: pointer to the string to be checked
 * Return: length of the string checked
*/

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
 * _strdup - Returns a pointer to a newly-allocated space in memory
 * @str: The string to be copied
 *
 * Return: NULL if (str == NULL) or insufficient memory is available,
 *         else, a pointer to the duplicated string.
 */

char *_strdup(char *str)
{
	unsigned int i = 0;
	unsigned int strlen = 0;
	char *cpy_str = NULL;

	if (str == NULL)
		return (NULL);

	for (strlen = 0; str[strlen] != '\0'; strlen++)
		;

	cpy_str = malloc((strlen + 1) * sizeof(char));

	if (cpy_str == NULL)
		return (NULL);

	for (i = 0; i < strlen; i++)
	{
		cpy_str[i] = str[i];
	}

	cpy_str[strlen] = '\0';

	return (cpy_str);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: converted integer
 */

int _atoi(char *s)
{
	int i = 0, d = 0, n = 0, len = 0, f = 0, digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';

			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;

			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}

/**
 * *_strcpy - copies the pointed string and the terminating null byte
 * @dest: pointer to the buffer from which string is copied
 * @src: the string to be copied
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len = 0, i = 0;
	char *srcpy = src;

	while (srcpy[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = srcpy[i];
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * is_cdir - checks if ":" is in the current directory
 * @path: character pointer
 * @i: type integer pointer of index
 * Return: 1 if the path is searchable in the cd, 0 otherwise
 */

int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
		*i += 1;

	if (path[*i])
		*i += 1;

	return (0);
}
