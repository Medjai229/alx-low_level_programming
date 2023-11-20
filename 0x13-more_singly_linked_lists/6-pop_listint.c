#include "lists.h"

/**
 * pop_listint - delets the head node of a singly linked list
 * @head: pointer to the head of the singly linked list
 *
 * Return: value of the removed node
 */
int pop_listint(listint_t **head)
{
	listint_t *node;
	int n;

	if (!head || !*head)
		return (0);

	node = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = node;

	return (n);
}
