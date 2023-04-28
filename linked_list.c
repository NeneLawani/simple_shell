#include "main.h"

/**
 * add_end_node - adds a separator node to end of list
 *
 * @head: represents the head of the linked list
 * @sep: separator to be added
 * Return: NULL on failure, and address of the head on success
 */

sep_t *add_end_node(sep_t **head, char sep)
{
	sep_t *new, *temp;

	new = malloc(sizeof(sep_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	new->sep = sep;
	new->next = NULL;

	if (!(*head))
		*head = new;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - a function that frees a separation list
 * @head: represents the head of the linked list
 */

void free_sep_list(sep_t **head)
{
	sep_t *temp;
	sep_t *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line - adds a command line at the end of a line_list
 * @head: represents the head of the linked list
 * @line: represents the command line
 * Return: address of the head is returned
 */

line_t *add_line(line_t **head, char *line)
{
	line_t *new, *temp;

	new = malloc(sizeof(line_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	new->line = line;
	new->next = NULL;

	if (!(*head))
		*head = new;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_line_list - function that frees a line_list
 * @head: represents the head of the linked list
 * Return: does not return
 */

void free_line_list(line_t **head)
{
	line_t *temp;
	line_t *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
