#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - search a value with the jump search algorithm
 * @array: array to search
 * @size: size of the array
 * @value: value to search
 * Return: -1 or index of the value
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump = sqrt(size), i, j;

	if (!array)
		return (-1);

	for (i = 0; i < size; i += jump)
	{
		if (array[i] >= value)
			break;
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}
	printf("Value found between indexes [%ld] and [%ld]\n", i - jump, i);
	for (j = i - jump; j <= i && j < size; j++)
	{
		printf("Value checked array[%ld] = [%d]\n", j, array[j]);
		if (array[j] == value)
			return (j);
	}
	return (-1);
}
