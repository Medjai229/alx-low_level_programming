#include "lists.h"

/**
 * free_listint- frees memory from a singly linked list
 * @head: pointer to the head of the singly linked list
 */
void free_listint(listint_t *head)
{
	if (!head)
		return;

	free_listint(head->next);
	free(head);
}
