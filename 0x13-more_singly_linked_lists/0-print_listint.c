#include "lists.h"

/**
 * print_listint - print a singly linked list
 * @h: a pointer to the head of the singly linked list
 *
 * Return: number of node
 */
size_t print_listint(const listint_t *h)
{
	size_t i = 0;

	while (h)
	{
		printf("%i\n", h->n);
		h = h->next;
		i++;
	}

	return (i);
}
