#include "lists.h"

/**
 * add_node - adds a new node as the head node of a singly linked list
 * @head: pointer to head of singly linked list
 * @str: the string to add as the head of the list
 *
 * Return: the address to the new node or null if failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_head = malloc(sizeof(list_t));

	if (!head || !new_head)
		return (NULL);

	if (str)
	{
		new_head->str = strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
		new_head->len = _strlen(new_head->str);
	}

	new_head->next = *head;
	*head = new_head;
	return (new_head);
}
