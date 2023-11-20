#include "lists.h"

/**
 * free_listint2 - frees memory from a singly linked list
 * @head: pointer to the head of the singly linked list
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head)
	{
		while (*head != 0)
		{
			temp = *head;
			*head = temp->next;
			free(temp);
		}
	}
}
