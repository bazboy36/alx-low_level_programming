#include "search_algos.h"
#include <stdio.h>

/**
 * search_recursion - search recursively for the value
 * @array: array to search
 * @low: index min
 * @high: index max
 * @size: size of the array
 * @value: value to search
 * Return: -1 or the index of the value
 */
int search_recursion(int *array, int low, int high, size_t size, int value)
{
	size_t pos = low + (((double)(high - low) / (array[high] - array[low]))
	* (value - array[low]));

	if (pos > size - 1)
	{
		printf("Value checked array[%ld] is out of range\n", pos);
		return (-1);
	}

	printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);

	if (array[pos] == value)
		return (pos);

	if (array[pos] < value)
		return (search_recursion(array, pos + 1, high, size, value));
	else
		return (search_recursion(array, low, pos - 1, size, value));
}

/**
 * interpolation_search - search with the interpolation algorithm
 * @array: array to search
 * @size: size of the array
 * @value: value to search
 * Return: -1 or the index of the value
 */
int interpolation_search(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (search_recursion(array, 0, size - 1, size, value));
}
