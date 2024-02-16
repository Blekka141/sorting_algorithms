#include "sort.h"

/**
 * bitonic_sort - Sort an array of integers in ascending order
 * using the Bitonic Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    bitonic_recursive(array, size, 1, size);
}

/**
 * bitonic_recursive - Perform the recursive Bitonic Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * @dir: Direction of the sort (1 for ascending, 0 for descending)
 * @full_size: Full size of the array
 */
void bitonic_recursive(int *array, size_t size, int dir, size_t full_size)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        bitonic_recursive(array, mid, !dir, full_size);
        bitonic_recursive(array + mid, mid, dir, full_size);
        bitonic_merge(array, size, dir, full_size);
        printf("Result [%lu/%lu] (%s):\n", size, full_size, dir ? "UP" : "DOWN");
        print_array(array, size);
    }
}

/**
 * bitonic_merge - Merge two subarrays in Bitonic Sort
 * @array: Array containing the subarrays
 * @size: Size of each subarray
 * @dir: Direction of the sort (1 for ascending, 0 for descending)
 * @full_size: Full size of the array
 */
void bitonic_merge(int *array, size_t size, int dir, size_t full_size)
{
    if (size > 1)
    {
        size_t k = size / 2, i;

        for (i = 0; i < k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
                swap(&array[i], &array[i + k]);
        }
        bitonic_merge(array, k, dir, full_size);
        bitonic_merge(array + k, k, dir, full_size);
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
