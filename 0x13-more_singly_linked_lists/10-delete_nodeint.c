#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index
 * of a listint_t linked list
 * @head: pointer to the head
 * @index: number of the node to be deleted
 *
 * Return: 1 if success -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *node = *head;
	unsigned int i;

	if (!node)
		return (-1);

	if (!index)
	{
		*head = (*head)->next;
		free(node);
		return (1);
	}

	for (i = 0; i < index - 1; i++)
	{
		if (!node->next)
			return (-1);

		node = node->next;
	}

	temp = node->next;
	node->next = temp->next;
	free(temp);
	return (1);
}
