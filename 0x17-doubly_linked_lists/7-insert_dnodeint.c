#include "lists.h"

/**
 * insert_dnodeint_at_index - function that inserts new node at given position.
 * @h: head pointer of a doubly linked list.
 * @idx:  index of the list where the new node should be added. Starts at 0.
 * @n: data part of the new node.
 * Return: the address of the new node, or NULL if it failed.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *aux1 = *h, *aux2 = *h, *new;
	unsigned int node = 0;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		if (*h != NULL)
		{	new->next = aux1;
			aux1->prev = new;	}
		else
			new->next = NULL;
		new->prev = NULL;
		*h = new;
		return (new);
	}
	else if (*h != NULL)
	{
		aux2 = aux2->next;
		while (aux2 && node < (idx - 1))
		{	node++;
			aux1 = aux1->next;
			aux2 = aux2->next;	}
		if (node == (idx - 1))
		{
			new->next = aux2;
			new->prev = aux1;
			aux1->next = new;
			if (aux2 != NULL)
				aux2->prev = new;
			return (new);
		}
	}
	free(new);
	return (NULL);
}

