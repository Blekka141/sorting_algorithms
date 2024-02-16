#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list of integers in ascending order
 * using Insertion Sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev, *next;

    if (list == NULL || *list == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        next = current->next;
        while (current->prev != NULL && current->n < current->prev->n)
        {
            prev = current->prev;
            current->prev = prev->prev;
            prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = prev;
            current->next = prev;
            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;
            prev->prev = current;
            print_list(*list);
        }
        current = next;
    }
}
