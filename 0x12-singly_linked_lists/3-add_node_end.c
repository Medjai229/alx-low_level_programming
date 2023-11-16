#include "lists.h"

/**
 ** add_node_end - adds a new node to the end of  a singly linked list
 * @head: pointer to head of singly linked list
 * @str: the string to add as the end node of the list
 *
 * Return: the address to the new node or null if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_end = malloc(sizeof(list_t));
	list_t *node = *head;

	if (!head || !new_end)
		return (NULL);

	if (str)
	{
		new_end->str = strdup(str);
		if (!new_end->str)
		{
			free(new_end);
			return (NULL);
		}
		new_end->len = _strlen(new_end->str);
	}

	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_end;
	}
	else
	{
		*head = new_end;
	}

	return (new_end);
}
