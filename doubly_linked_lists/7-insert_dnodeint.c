#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the head of the list
 * @idx: index to insert the new node (starting at 0)
 * @n: value of the new node
 * Return: address of new node, or NULL if failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *temp;
    unsigned int i;

    if (!h)
        return (NULL);

    if (idx == 0)
        return (add_dnodeint(h, n));

    temp = *h;
    for (i = 0; i < idx - 1 && temp != NULL; i++)
        temp = temp->next;

    if (!temp)
        return (NULL);

    if (!temp->next)
        return (add_dnodeint_end(h, n));

    new_node = malloc(sizeof(dlistint_t));
    if (!new_node)
        return (NULL);

    new_node->n = n;
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;

    return (new_node);
}
