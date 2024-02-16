#include "sort.h"

/**
 * quick_sort_hoare - Sort an array of integers in ascending order
 * using Quick Sort algorithm with Hoare partition scheme
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - Perform the recursive Quick Sort algorithm
 * @array: Array to be sorted
 * @lo: Starting index of the partition to be sorted
 * @hi: Ending index of the partition to be sorted
 * @size: Size of the array
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
    if (lo < hi)
    {
        ssize_t p = partition(array, lo, hi, size);
        quicksort(array, lo, p, size);
        quicksort(array, p + 1, hi, size);
    }
}

/**
 * partition - Perform the partition step of Quick Sort
 * @array: Array to be sorted
 * @lo: Starting index of the partition to be sorted
 * @hi: Ending index of the partition to be sorted
 * @size: Size of the array
 *
 * Return: Index of the pivot element after partitioning
 */
ssize_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
    int pivot = array[hi];
    ssize_t i = lo - 1, j = hi + 1;

    while (1)
    {
        do
            i++;
        while (array[i] < pivot);

        do
            j--;
        while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * swap - Swap two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
