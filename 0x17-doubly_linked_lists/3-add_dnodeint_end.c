#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the beginning of a dlistint_t list
 * @head: address of the head node
 * @n: value of the new node
 *
 * Return: address of the new node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));
	dlistint_t *temp = NULL;

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!head || !(*head))
	{
		*head = new_node;
		return (new_node);
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		new_node->prev = temp;
		temp->next = new_node;
		return (new_node);
	}

	return (NULL);
}
