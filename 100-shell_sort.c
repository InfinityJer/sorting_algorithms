#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	/* Calculate the initial gap using Knuth sequence */
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		/* Perform insertion sort with given gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			/* Shift elements until correct position for temp is found */
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		/* Print the array after each pass with decreasing gap */
		print_array(array, size);
		/* Calculate the next gap using Knuth sequence */
		gap = (gap - 1) / 3;
	}
}
