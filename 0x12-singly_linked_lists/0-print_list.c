#include "lists.h"

/**
 * print_list - print a singly linked list
 * @h: pointer to the head of the singly linked list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		if (h->str != 0)
			printf("[%i] %s\n", h->len, h->str);
		else
			printf("[0] (nil)\n");
		h = h->next;
		i++;
	}

	return (i);
}
