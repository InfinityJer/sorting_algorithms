#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to a pointer to the head of the doubly linked list.
 * @node1: Pointer to the first node to swap.
 * @node2: Pointer to the second node to swap.
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
    listint_t *prev, *next;

    prev = (*node1)->prev;
    next = (*node2)->next;

    if (prev != NULL)
        prev->next = *node2;
    else
        *list = *node2;

    if (next != NULL)
        next->prev = *node1;

    (*node1)->prev = *node2;
    (*node2)->next = *node1;

    (*node1)->next = next;
    (*node2)->prev = prev;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do
    {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, &current, &(current->next));
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, &(current->prev), &current);
                print_list(*list);
                swapped = 1;
            }
        }
    } while (swapped);
}

