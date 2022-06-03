#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* loop_list_count - function counts the number of node in a looped linked list
* @head: Pointer to the head of the linked list
* Return: The number of unique nodes in the list if looped or 0 otherwise
*/

size_t loop_list_count(listint_t *head)
{
	listint_t *new, *temp;
	size_t node = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	new =  head->next;
	temp = (head->next)->next;

	while (temp)
	{
		if (new == temp)
		{
			new = head;
			while (new != temp)
			{
				node++;
				new = new->next;
				temp = temp->next;
			}

			new = new->next;
			while (new != temp)
			{
				node++;
				new = new->next;
			}
			return (node);
		}
		new = new->next;
		temp = (temp->next)->next;
	}
	return (0);
}

/**
* free_listint_safe - function frees a linked list
* @h: head of the node
* Return: The size of thr list that was freed
*/

size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;
	size_t node, index;

	node = loop_list_count(*h);

	if (node == 0)
	{
		for (; h != NULL && *h != NULL; node++)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
		}
	}
	else
	{
		for (index = 0; index < node; index++)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
		}

		*h = NULL;
	}

	h = NULL;
	return (node);
}
