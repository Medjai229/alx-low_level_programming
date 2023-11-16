#include "lists.h"

/**
 * free_list - frees memory of a singly liniked list
 * @head: pointer to the head of a singly linked list
 */
void free_list(list_t *head)
{
	if (!head)
		return;
	free_list(head->next);
	free(head->str);
	free(head);
}
