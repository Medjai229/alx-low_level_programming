#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: the size of the array
 *
 * Return: a pointer to the newly created hash table
 * If something went wrong the function returns null
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table = malloc(sizeof(shash_table_t));
	unsigned long int index;

	if (new_table == NULL)
		return (NULL);

	new_table->size = size;
	new_tabl->array = malloc(sizeof(shash_node_t *) * size);

	if (new_table->array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		new_table->array[index] = NULL;

	new_table->shead = NULL;
	new_table->stail = NULL;

	return (new_table);
}
