#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort_radix - Sorts an array of integers using counting sort
 * @array: The input array
 * @size: The size of the array
 * @significant: The significant digit to sort on
 */
void counting_sort_radix(int *array, size_t size, int significant)
{
	int *output, *count;
	size_t i;
	int max_value = 10; /* Radix sort: Base 10 (0-9 digits) */

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	count = calloc(max_value, sizeof(int));
	if (!count)
	{
		free(output);
		return;
	}

	for (i = 0; i < size; i++)
		count[(array[i] / significant) % 10]++;

	for (i = 1; i < (size_t)max_value; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / significant) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / significant) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: The input array
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_value = 0;
	size_t i;
	int significant;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	for (significant = 1; max_value / significant > 0; significant *= 10)
	{
		counting_sort_radix(array, size, significant);
		print_array(array, size);
	}
}

