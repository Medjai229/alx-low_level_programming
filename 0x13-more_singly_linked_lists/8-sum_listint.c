#include "lists.h"

/**
 * sum_listint - adds all the data in a singly linked list
 * @head: pointer to the head of a singly linked list
 *
 * Return: sum of all data nodes in the list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
