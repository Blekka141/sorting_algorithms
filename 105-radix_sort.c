#include "sort.h"

/**
 * cocktail_sort_list - Sort a doubly linked list of integers in ascending order
 * using the Cocktail Shaker Sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *start = *list, *end = NULL;
    int swapped = 1;

    while (swapped)
    {
        swapped = 0;
        while (start && start->next != end)
        {
            if (start->n > start->next->n)
            {
                swap_nodes(list, start, start->next);
                print_list(*list);
                swapped = 1;
            }
            else
                start = start->next;
        }
        if (!swapped)
            break;
        swapped = 0;
        end = start;
        while (start && start->prev != NULL)
        {
            if (start->n < start->prev->n)
            {
                swap_nodes(list, start->prev, start);
                print_list(*list);
                swapped = 1;
            }
            else
                start = start->prev;
        }
    }
}
