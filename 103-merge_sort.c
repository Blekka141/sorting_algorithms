#include "sort.h"

/**
 * quick_sort - Sort an array of integers in ascending order using Quick Sort
 * with Lomuto Partition Scheme
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int pivot_idx;

    if (low < high)
    {
        pivot_idx = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot_idx - 1, size);
        quick_sort_recursive(array, pivot_idx + 1, high, size);
    }
}

/**
 * lomuto_partition - Partition the array using Lomuto scheme
 * @array: Array to be partitioned
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 * Return: Index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j, temp;

    for (j = low; j <= high - 1; j++)
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
