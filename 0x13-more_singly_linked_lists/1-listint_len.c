#include "lists.h"

/**
 * lustint_len - return the number of node in a singly linked list
 * @h: pointer to the head of the sinlgy linked list
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t i = 0;

	while(h)
	{
		h = h->next;
		i++;
	}

	return (i);
}
