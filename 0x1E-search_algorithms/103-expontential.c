#include "search_algos.h"
#include <stdio.h>

/**
 * binary_rec - do a binary search recursively
 * @array: array to search
 * @left: min index
 * @right: max index
 * @value: value to find
 * Return: -1 or the index of the value
 */
int binary_rec(int *array, size_t left, size_t right, int value)
{
	size_t i, mid = (left + right) / 2;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		if (i < right)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}

	if (left == right)
		return (-1);

	if (array[mid] == value && value > 0 && array[mid - 1] == value)
		return (binary_rec(array, left, mid, value));

	if (array[mid] == value)
		return (mid);

	if (array[mid] > value)
		return (binary_rec(array, left, mid - 1, value));
	else
		return (binary_rec(array, mid + 1, right, value));

	return (-1);
}

/**
 * exponential_search - search using the exponential algorithm
 * @array: array to search in
 * @size: size of the array
 * @value: value to search
 * Return: -1 or the index of the value
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array)
		return (-1);

	for (i = 1; i < size; i *= 2)
	{
		if (array[i] >= value)
			break;
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}
	if (i < size - 1)
	{
		printf("Value found between indexes [%ld] and [%ld]\n", i / 2, i);
		return (binary_rec(array, i / 2, i, value));
	}
	else
	{
		printf("Value found between indexes [%ld] and [%ld]\n", i / 2, size - 1);
		return (binary_rec(array, i / 2, size - 1, value));
	}
	return (-1);
}
