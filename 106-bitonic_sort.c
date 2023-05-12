#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @start: The starting index of the sequence in the array to sort.
 * @size: The size of the sequence to sort.
 * @dir: The direction to sort in (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        for (size_t i = start; i < start + mid; i++)
        {
            if ((array[i] > array[i + mid] && dir == 1) ||
                (array[i] < array[i + mid] && dir == 0))
            {
                swap_ints(&array[i], &array[i + mid]);
                printf("Result [%lu/%lu] (%s):\n", size, size, dir == 1 ? "UP" : "DOWN");
                print_array(array, size);
            }
        }
        bitonic_merge(array, start, mid, dir);
        bitonic_merge(array, start + mid, mid, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive helper function for Bitonic sort.
 * @array: An array of integers.
 * @start: The starting index of the sequence in the array to sort.
 * @size: The size of the sequence to sort.
 * @dir: The direction to sort in (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        bitonic_sort_recursive(array, start, mid, 1);
        bitonic_sort_recursive(array, start + mid, mid, 0);
        bitonic_merge(array, start, size, dir);
    }
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (i.e., size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}
