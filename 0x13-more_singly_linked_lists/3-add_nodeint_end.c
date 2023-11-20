#include "lists.h"

/**
 * add_nodeint_end - add a node to the end of a singly linked list
 * @head: pointer to the first node
 * @n: the value for the new node
 *
 * Return: pointer to the new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_end = malloc(sizeof(listint_t));
	listint_t *node;

	if (!head || !new_end)
		return (NULL);

	new_end->next = NULL;
	new_end->n = n;

	if (!*head)
	{
		*head = new_end;
	}
	else
	{
		node = *head;

		while (node->next)
			node = node->next;

		node->next = new_end;
	}

	return (new_end);
}
