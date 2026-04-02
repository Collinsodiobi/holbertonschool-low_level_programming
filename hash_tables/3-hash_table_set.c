#include "hash_tables.h"

/**
 * hash_table_set - adds or updates an element in a hash table
 * @ht: pointer to the hash table
 * @key: key string (must not be empty)
 * @value: value string (will be duplicated)
 *
 * Return: 1 if success, 0 if failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;
	char *value_copy;

	if (!ht || !key || !*key || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	/* Check if key exists */
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			value_copy = strdup(value);
			if (!value_copy)
				return (0);
			current->value = value_copy;
			return (1);
		}
		current = current->next;
	}

	/* Create new node */
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	/* Insert at beginning (collision handling) */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
