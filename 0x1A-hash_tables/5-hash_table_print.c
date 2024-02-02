#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *traverse;
	unsigned long int index;
	int flag = 0;

	if (ht == NULL)
		return;

	printf("{");

	for (index = 0; index < ht->size; index++)
	{
		traverse = ht->array[index];

		while (traverse != NULL)
		{
			if (flag == 1)
				printf(", ");
			printf("'%s': '%s'", traverse->key, traverse->value);
			flag = 1;
			traverse = traverse->next;
		}
	}
	printf("}\n");
}

