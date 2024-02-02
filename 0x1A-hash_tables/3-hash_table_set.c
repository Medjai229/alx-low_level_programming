#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table to add or update the key/value
 * @key: the key
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *traverse;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == 0 || value == NULL)
		return (0);

	index = key_index((const unsigned char *) key, ht->size);
	traverse = ht->array[index];

	while (traverse)
	{
		if (strcmp(traverse->key, key) == 0)
			break;
		traverse = traverse->next;
	}

	if (traverse == NULL)
	{
		new_node = malloc(sizeof(hash_node_t));
		if (new_node == NULL)
			return (0);

		new_node->key = strdup(key);
		if (new_node->key == NULL)
			return (0);

		new_node->value = strdup(value);
		if (new_node->value == NULL)
			return (0);

		new_node->next = ht->array[index];
		ht->array[index] = new_node;
	}
	else
	{
		free(traverse->value);
		traverse->value = strdup(value);
	}

	return (1);
}

