#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - test dlistint_len
 * Return: 0
 */
int main(void)
{
	dlistint_t *head;
	dlistint_t *new;
	dlistint_t hello = {8, NULL, NULL};
	size_t n;

	head = &hello;
	new = malloc(sizeof(dlistint_t));
	if (!new)
	{
		dprintf(2, "Error: Can't malloc\n");
		return (EXIT_FAILURE);
	}
	new->n = 9;
	head->prev = new;
	new->next = head;
	new->prev = NULL;
	head = new;

	n = dlistint_len(head);
	printf("-> %lu elements\n", n);

	free(new);
	return (0);
}
