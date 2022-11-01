#include "search_algos.h"
#include <stdio.h>

/**
 * linear_skip - linear skip search on a linked list
 * @list: linked list
 * @value: value to search
 * Return: NULL or a pointer to the node of the value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *check = NULL, *ptr = NULL;

	if (!list)
		return (NULL);

	ptr = list;
	check = list;

	while (ptr->next)
	{
		if (ptr->index > 0)
			printf("Value checked at index [%ld] = [%d]\n", ptr->index, ptr->n);
		if (ptr->n >= value)
			break;
		check = ptr;
		if (ptr->express)
			ptr = ptr->express;
		else
		{
			while (ptr->next)
			{
				if (ptr->n >= value)
					break;
				ptr = ptr->next;
			}
		}
	}

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
