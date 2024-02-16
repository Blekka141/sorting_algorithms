#include "sort.h"

/**
 * partition - partitions the array and returns the pivot index
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: index of the pivot
 **/
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            if (i != j)
                print_array(array, size);
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    if (i + 1 != high)
        print_array(array, size);
    return (i + 1);
}

/**
 * quicksort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 **/
void quicksort(int *array, int low, int high, size_t size)
{
    int pivot_idx;

    if (low < high)
    {
        pivot_idx = partition(array, low, high, size);
        quicksort(array, low, pivot_idx - 1, size);
        quicksort(array, pivot_idx + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 **/
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quicksort(array, 0, size - 1, size);
}
