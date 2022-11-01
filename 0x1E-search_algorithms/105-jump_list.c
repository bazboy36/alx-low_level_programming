#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_list - jump search algorithm in a singly linked list
 * @list: singly linked list
 * @size: size of the singly linked list
 * @value: value to search
 * Return: NULL or a pointer to the node of the value
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump = sqrt(size);
	listint_t *check = NULL, *ptr = NULL;

	if (!list)
		return (NULL);

	ptr = list;
	check = list;

	while (ptr->next)
	{
		if (ptr->index && ptr->index % jump == 0)
		{
			printf("Value checked at index [%ld] = [%d]\n", ptr->index, ptr->n);
			if (ptr->n >= value)
				break;
			check = ptr;
		}
		ptr = ptr->next;
	}
	if (!ptr->next)
		printf("Value checked at index [%ld] = [%d]\n", ptr->index, ptr->n);

	printf("Value found between indexes ");
	printf("[%ld] and [%ld]\n", check->index, ptr->index);

	while (check)
	{
		printf("Value checked at index [%ld] = [%d]\n", check->index, check->n);
		if (check->n == value)
			return (check);
		check = check->next;
	}
	return (NULL);
}
