#include "sort.h"

/**
 * swap_ints - Swaps two integers.
 *
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions a sub-array according to the Lomuto scheme.
 *
 * @array: The array to partition.
 * @size: The size of the array.
 * @left: The starting index of the sub-array to partition.
 * @right: The ending index of the sub-array to partition.
 *
 * Return: The index of the partitioning element.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = left - 1, j;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[right] < array[i + 1])
	{
		swap_ints(&array[i + 1], &array[right]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * lomuto_sort - Sorts an array of integers in ascending order
 * using the Lomuto scheme.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 * @left: The starting index of the sub-array to sort.
 * @right: The ending index of the sub-array to sort.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	if (left < right)
	{
		int partition = lomuto_partition(array, size, left, right);

		lomuto_sort(array, size, left, partition - 1);
		lomuto_sort(array, size, partition + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the quicksort algorithm.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
