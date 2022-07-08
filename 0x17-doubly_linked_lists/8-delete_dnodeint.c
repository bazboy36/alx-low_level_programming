#include "lists.h"

/**
 * delete_dnodeint_at_index - function that that deletes node at index in list.
 * @head: head pointer of a doubly linked list.
 * @index:  index of the node that should be deleted. Starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *aux1 = *head, *aux2 = *head, *to_delete = *head;
	unsigned int node = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		if ((*head)->next != NULL)
		{
			aux1->next->prev = NULL;
			*head = (*head)->next;
		}
		else
			*head = NULL;
		free(to_delete);
		return (1);
	}
	to_delete = to_delete->next;
	aux2 = aux2->next;
	while (aux2 && node < (index - 1))
	{	node++;
		aux1 = aux1->next;
		aux2 = aux2->next;
		to_delete = to_delete->next;	}
	if (node == (index - 1))
	{
		aux1->next = aux2->next;
		if (aux2->next != NULL)
			aux2->next->prev = aux1;
		free(to_delete);
		return (1);
	}
	return (-1);
}
