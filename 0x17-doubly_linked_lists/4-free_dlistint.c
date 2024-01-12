#include "lists.h"

/**
 * free_flistint - frees a dlistint_t list
 * @head: address of the head node
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(node);
	}
}
