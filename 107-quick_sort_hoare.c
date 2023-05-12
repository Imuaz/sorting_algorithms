#include "sort.h"

/**
 * swap_ints - swaps two integer values.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - performs the Hoare partition scheme on a
 * subset of an array.
 * @array: The array to partition.
 * @size: The size of the array.
 * @left: The starting index of the subset.
 * @right: The ending index of the subset.
 *
 * Return: The final partition index.
 *
 * Description: The last element of the subset is chosen as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int above = left - 1;
	int below = right + 1;

	while (1)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);
		if (above >= below)
			return (above);

		swap_ints(&array[above], &array[below]);
		print_array(array, size);
	}
}

/**
 * hoare_sort - recursively sorts an array using the Hoare partition scheme.
 * @array: The array to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition.
 * @right: The ending index of the array partition.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	if (left < right)
	{
		int part = hoare_partition(array, size, left, right);

		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - ports an array of integers in ascending
 * order using the quicksort algorithm
 * and the Hoare partition scheme.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
