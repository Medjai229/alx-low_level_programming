nclude "lists.h"

/**
 * find_listint_loop - finds a loop in a singly linked list
 * @head: pointer to the head of the list to search
 *
 * Return: address of node where loop start
 */
listint_t *find_listint_loop(listint_t *head)
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
