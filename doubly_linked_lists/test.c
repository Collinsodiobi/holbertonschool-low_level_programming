#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - Test the doubly linked list functions
 *
 * Return: Always 0
 */
int main(void)
{
	dlistint_t *head;
	size_t len;

	head = NULL;

	/* Add nodes at the beginning */
	add_dnodeint(&head, 1);
	add_dnodeint(&head, 2);
	add_dnodeint(&head, 3);

	printf("List after adding nodes at the beginning:\n");
	print_dlistint(head);

	/* Add nodes at the end */
	add_dnodeint_end(&head, 4);
	add_dnodeint_end(&head, 5);

	printf("List after adding nodes at the end:\n");
	print_dlistint(head);

	/* Check length */
	len = dlistint_len(head);
	printf("Length of list: %lu\n", len);

	/* Free list */
	free_dlistint(head);
	head = NULL;

	printf("List freed.\n");

	return (0);
}
