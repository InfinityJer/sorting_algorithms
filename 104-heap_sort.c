#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start'
 *
 * @array: The input array
 * @start: The root of the heap to repair
 * @end: The end of the array
 * @size: The size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;

    while ((2 * root + 1) <= end)
    {
        size_t child = 2 * root + 1;
        size_t swap = root;

        if (array[swap] < array[child])
            swap = child;
        if (child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;
        if (swap == root)
            return;
        swap_int(&array[root], &array[swap]);
        print_array(array, size);
        root = swap;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    for (i = (size / 2) - 1; i >= 0; i--)
        sift_down(array, (size_t)i, size - 1, size);

    for (i = size - 1; i > 0; i--)
    {
        swap_int(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, 0, i - 1, size);
    }
}

