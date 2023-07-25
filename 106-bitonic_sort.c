#include <stdio.h>
#include "sort.h"

/**
 * bitonic_compare - Compares and swaps elements based on the direction
 * @array: The input array
 * @size: The size of the array
 * @up: The direction of sorting (1 for up, 0 for down)
 */
void bitonic_compare(int *array, size_t size, int up)
{
    size_t dist = size / 2;
    size_t i;

    for (i = 0; i < dist; i++)
    {
        if ((array[i] > array[i + dist]) == up)
        {
            /* Swap elements */
            int temp = array[i];
            array[i] = array[i + dist];
            array[i + dist] = temp;
            printf("Swap: %d and %d\n", array[i], array[i + dist]);
        }
    }
}

/**
 * bitonic_merge - Merges a bitonic sequence
 * @array: The input array
 * @size: The size of the array
 * @up: The direction of sorting (1 for up, 0 for down)
 */
void bitonic_merge(int *array, size_t size, int up)
{
    if (size <= 1)
        return;

    printf("Merging [%lu/%lu] (%s):\n", size, size, up ? "UP" : "DOWN");
    print_array(array, size);

    bitonic_compare(array, size, up);
    bitonic_merge(array, size / 2, up);
    bitonic_merge(array + size / 2, size / 2, up);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: The input array
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (size <= 1)
        return;

    /* Sort left part in ascending order */
    bitonic_sort(array, size / 2);

    /* Sort right part in descending order */
    bitonic_sort(array + size / 2, size / 2);

    /* Merge the whole sequence in ascending order */
    bitonic_merge(array, size, 1);
}

