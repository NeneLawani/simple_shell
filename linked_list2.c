#include "main.h"

/**
 * add_tail_node - a function that adds a node to end list
 * @head: represents the head of the linked list
 * @var_len: represents the length of the variable
 * @val: represents the value of the variable
 * @len_val: represents the length of the value
 * Return: address of the head is returned
 */

list_t *add_tail_node(list_t **head, int var_len, char *val, int len_val)
{
	list_t *new, *temp;

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	new->var_len = var_len;
	new->val = val;
	new->len_val = len_val;

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
 * free_list - function that frees a list_t list
 * @head: represents the head of the linked list
 * Return: does not return
 */

void free_list(list_t **head)
{
	list_t *temp;
	list_t *curr;

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
