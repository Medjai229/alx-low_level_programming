#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a singly linked list
 * @head: pointer to the head of the singly linked list
 * @index: index of the node to find
 *
 * Return: nth node value in the list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (!head)
			return (NULL);

		head = head->next;
	}

	return (head);
}
