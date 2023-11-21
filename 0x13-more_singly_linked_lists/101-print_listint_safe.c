#include "lists.h"

/**
 * _r - reallocates memory for an array of pointers to node of a listint_t list
 * @list: the old list
 * @size: size of the new list
 * @new: new node to add to the list
 *
 * Return: pointer to the new list
 */
const listint_t **_r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **new_list;
	size_t i;

	new_list = malloc(size * sizeof(listint_t *));

	if (!new_list)
	{
		free(list);
		exit(98);
	}

	for (i = 0; i < size - 1; i++)
		new_list[i] = list[i];
	new_list[i] = new;

	free(list);
	return (new_list);
}

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head
 *
 * Return: number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i, n = 0;
	const listint_t **list = NULL;

	while (head)
	{
		for (i = 0; i < n; i++)
		{
			if (head == list[i])
			{
				printf("-> [%p] %i\n", (void *)head, head->n);
				free(list);
				return (n);
			}
		}
		n++;
		list = _r(list, n, head);
		printf("[%p] %i\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (n);
}
