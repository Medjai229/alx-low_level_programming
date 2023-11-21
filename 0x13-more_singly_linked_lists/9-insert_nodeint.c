#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the head
 * @idx: where the node should be added
 * @n: value of the new node
 *
 * Return: adress of the new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node, *new = malloc(sizeof(listint_t));
	unsigned int i;

	if (!head || !new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (!idx)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	node = *head;

	for (i = 0; i < idx - 1; i++)
	{
		if (!node || !node->next)
			return (NULL);

		node = node->next;
	}

	new->next = node->next;
	node->next = new;

	return (new);
}
