#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *traverse, *tmp;

	if (ht == NULL)
		return;

	for (index = 0; index < ht->size; index++)
	{
		traverse = ht->array[index];

		while (traverse != NULL)
		{
			tmp = traverse->next;
			free(traverse->key);
			free(traverse->value);
			free(traverse);
			traverse = tmp;
		}
	}

	free(ht->array);
	free(ht);
}
