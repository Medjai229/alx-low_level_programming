#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to the head
 *
 * Return: address of the new head
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *node, *next_node = NULL;

	if (!head || !*head)
		return (NULL);

	node = *head;
	*head = NULL;

	while (node)
	{
		next_node = node->next;
		node->next = *head;
		*head = node;
		node = next_node;
	}

	return (*head);
}
