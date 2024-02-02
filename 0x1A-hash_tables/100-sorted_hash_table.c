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
 * make_shash_node - makes a node for the sorted hash table
 * @key: key for the data
 * @value: data to be stored
 *
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *shn;

	shn = malloc(sizeof(shash_node_t));
	if (shn == NULL)
		return (NULL);
	shn->key = strdup(key);
	if (shn->key == NULL)
	{
		free(shn);
		return (NULL);
	}
	shn->value = strdup(value);
	if (shn->value == NULL)
	{
		free(shn->key);
		free(shn);
		return (NULL);
	}
	shn->next = shn->snext = shn->sprev = NULL;
	return (shn);
}

/**
 * add_to_sorted_list - add a node to the sorted (by key's ASCII) linked list
 * @table: the sorted hash table
 * @node: the node to add
 *
 * Return: void
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *tmp;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	tmp = table->shead;
	while (tmp != NULL)
	{
		if (strcmp(node->key, tmp->key) < 0)
		{
			node->snext = tmp;
			node->sprev = tmp->sprev;
			tmp->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		tmp = tmp->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: sorted hash table
 * @key: key to the data
 * @value: data to add
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *new_value;
	shash_node_t *shn, *tmp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(tmp->value);
			tmp->value = new_value;
			return (1);
		}
		tmp = tmp->next;
	}
	shn = make_shash_node(key, value);
	if (shn == NULL)
		return (0);
	shn->next = ht->array[index];
	ht->array[index] = shn;
	add_to_sorted_list(ht, shn);
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

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *) key, ht->size);

	if (index >= ht->size)
		return (NULL);

	node = ht->shead;

	while (node != NULL && strcmp(node->key, key) != 0)
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
