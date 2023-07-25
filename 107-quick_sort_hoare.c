#include "sort.h"

/* Function prototypes */
void hoare_quick_sort(int *array, int low, int high);
int hoare_partition(int *array, int low, int high);
void swap_int(int *a, int *b);

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm (Hoare partition scheme).
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    hoare_quick_sort(array, 0, size - 1);
}

/**
 * hoare_quick_sort - Recursive function to sort the array using the Hoare
 *                    partition scheme.
 *
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 */
void hoare_quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high);
        hoare_quick_sort(array, low, pivot);
        hoare_quick_sort(array, pivot + 1, high);
    }
}

/**
 * hoare_partition - Hoare partition scheme to rearrange the elements.
 *
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The index of the pivot element.
 */
int hoare_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap_int(&array[i], &array[j]);
        print_array(array, high + 1);
    }
}

/**
 * swap_int - Swaps two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

