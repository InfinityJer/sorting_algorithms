#include "sort.h"


/**
 * merge_sort - merge sort
 * desc: the Merge sort algorithm
 * @array: array
 * @size: size
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *i;

	if (array == NULL || size < 2)
		return;
	i = malloc(sizeof(int) * size), sort_recursive(array, i, 0, size);
	free(i);
}

/**
 * sort_recursive - sort recurive
 * desc: sort
 * @array: array
 * @i: inner number
 * @p: the beginning
 * @q: the end
 * Return: void
 */
void sort_recursive(int *array, int *i, int p, int q)
{
	int k;

	if (q - p > 1)
	{
		k = q - p;
		k = k / 2 + p;
		sort_recursive(array, i, p, k), sort_recursive(array, i, k, q);
		merge_arrays(array, i, p, k, q);
	};
}

/**
 * merge_arrays - merge arrays in merge sort
 * desc: the Merge sort algorithm
 * @array: array
 * @in: inner number
 * @p: begining
 * @y: mid
 * @q: end
 * Return: void
 */
void merge_arrays(int *array, int *in, int p, int y, int q)
{
	int i, j, k;

	i = 0;
	j = 0;
	k = 0;
	printf("Merging...\n[left]: "), print_array(array + p, y - p);
	printf("[right]: "), print_array(array + y, q - y);
	for (i = p, j = y; i < y && j < q; k++)
		if (*(array + i) < *(array + j))
			*(in + k) = *(array + i++);
		else
			*(in + k) = *(array + j++);
	while (i < y)
		*(in + k++) = *(array + i++);
	while (j < q)
		*(in + k++) = *(array + j++);
	for (i = p, k = 0; i < q; i++)
		*(array + i) = *(in + k++);
	printf("[Done]: "), print_array(array + p, q - p);
}
