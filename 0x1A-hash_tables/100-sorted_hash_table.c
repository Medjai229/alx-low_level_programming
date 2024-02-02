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
	new_table->array = malloc(sizeof(shash_node_t *) * size);

	if (new_table->array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		new_table->array[index] = NULL;

	new_table->shead = NULL;
	new_table->stail = NULL;

	return (new_table);
}

/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: the sorted hash table to add or update the key/value
 * @key: the key
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *traverse;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key =='\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	traverse = ht->shead;

	while (traverse != NULL)
	{
		if (strcmp(traverse->key, key) == 0)
		{
			free(traverse->value);
			traverse->value = strdup(value);
			return (1);
		}
		traverse = traverse->snext;
	}

	new_node = malloc(sizeof(shash_node_t));

	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);

	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		traverse = ht->shead;
		while (traverse->snext != NULL && strcmp(traverse->key, key) < 0)
			traverse = traverse->snext;

		new_node->sprev = traverse;
		new_node->snext = traverse->snext;

		if (traverse->snext == NULL)
			ht->stail = new_node;
		else
			traverse->snext->sprev = new_node;

		traverse->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the sorted hash table to look into
 * @key: the key to look for
 *
 * Return: the value associated with the element
 * or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == 0)
		return (NULL);

	index = key_index((const unsigned char *) key, ht->size);

	if (index >= ht->size)
		return (NULL);

	node = ht->shead;

	while (node && strcmp(node->key, key) != 0)
		node = node->snext;

	if (node == NULL)
		return (NULL);

	return (node->value);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *traverse;
	int flag = 0;

	if (ht == NULL)
		return;

	traverse = ht->shead;

	printf("{");

	while (traverse != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", traverse->key, traverse->value);
		flag = 1;
		traverse = traverse->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *traverse;
	int flag = 0;

	if (ht == NULL)
		return;

	traverse = ht->stail;

	printf("{");

	while (traverse != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", traverse->key, traverse->value);
		flag = 1;
		traverse = traverse->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *traverse, *tmp;

	if (ht == NULL)
		return;

	traverse = ht->shead;

	while (traverse != NULL)
	{
		tmp = traverse->snext;
		free(traverse->key);
		free(traverse->value);
		free(traverse);
		traverse = tmp;
	}

	free(ht->array);
	free(ht);
}
