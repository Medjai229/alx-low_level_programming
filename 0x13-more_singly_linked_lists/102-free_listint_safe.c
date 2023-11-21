#include "lists.h"

/**
 * find_loop - finds a loop in a singly linked list
 * @head: pointer to the head of the list to search
 *
 * Return: address of node where loop start
 */
listint_t *find_loop(listint_t *head)
{
	listint_t *ptr, *last;

	if (!head)
		return (NULL);

	for (last = head->next; last != NULL; last = last->next)
	{
		if (last == last->next)
			return (last);

		for (ptr = head; ptr != last; ptr = ptr->next)
		{
			if (ptr == last->next)
				return (last->next);
		}
	}
	return (NULL);
}

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to the head
 *
 * Return: number of node in the list freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *next, *nodeloop;
	size_t n;
	int loop = 1;

	if (!h || !*h)
		return (0);

	nodeloop = find_loop(*h);

	for (n = 0; (*h != nodeloop || loop) && *h != NULL; *h = next)
	{
		n++;
		next = (*h)->next;

		if (*h == nodeloop && loop)
		{
			if (nodeloop == nodeloop->next)
			{
				free(*h);
				break;
			}
			n++;
			next = next->next;
			free((*h)->next);
			loop = 0;
		}
		free(*h);
	}
	*h = NULL;
	return (n);
}
