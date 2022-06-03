#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
* looped_listint_len - function counts the number of nodes
* in a looped linked list
* @head: The head node
* Return: 0 if list isnt looped or number of unique nodes in the list
*/
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *new, *temp;
	size_t node = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	new = head->next;
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
* print_listint_safe - funtion prints a linked list
* @head: head to the node
* Return: The number of nodes in the list
*/

size_t print_listint_safe(const listint_t *head)
{
	size_t node, index = 0;

	node = looped_listint_len(head);

	if (node == 0)
	{
		for (; head != NULL; node++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < node; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (node);
}
