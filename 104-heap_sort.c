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
 * max_heapify - Perform max heapify operation on a binary tree.
 * @array: The array representing the binary tree.
 * @size: The size of the array.
 * @base: The base index of the tree.
 * @root: The root index of the subtree to heapify.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < base && array[left] > array[largest])
		largest = left;

	if (right < base && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap_ints(&array[root], &array[largest]);
		print_array(array, size);
		max_heapify(array, size, base, largest);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order using
 *             the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort algorithm.
 * Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(&array[0], &array[i]);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
