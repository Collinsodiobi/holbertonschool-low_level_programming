#include "hash_tables.h"

/**
 * update_value - updates value of an existing key
 * @node: node to update
 * @value: new value
 *
 * Return: 1 on success, 0 on failure
 */
int update_value(hash_node_t *node, const char *value)
{
	char *new_value;

	new_value = strdup(value);
	if (!new_value)
		return (0);

	free(node->value);
	node->value = new_value;

	return (1);
}

/**
 * create_node - creates a new hash node
 * @key: key string
 * @value: value string
 *
 * Return: pointer to new node or NULL
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (NULL);

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	return (new_node);
}

/**
 * hash_table_set - adds or updates an element in a hash table
 * @ht: pointer to hash table
 * @key: key string
 * @value: value string
 *
 * Return: 1 if success, 0 if failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *current, *new_node;

	if (!ht || !key || !*key || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (update_value(current, value));
		current = current->next;
	}

	new_node = create_node(key, value);
	if (!new_node)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
