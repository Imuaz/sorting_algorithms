#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 * Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_bitonic(array, 0, size, size, 1);
}

/**
 * sort_bitonic - Sorts an array of integers in ascending or descending order
 * using the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @low_idx: The lowest index of the array or subarray that we
 * are working with.
 * @count: The number of elements in the array or subarray that we are
 * working with.
 * @maxsize: The maximum size of the array.
 * @dirctn: Determines if we are to sort the list in
 * ascending or descending order:
 * 1 - Sort in ascending order.
 * 0 - Sort in descending order.
 */
void sort_bitonic(int *array, int low_idx, int count, int maxsize, int dirctn)
{
	int k;

	if (count == 1)
		return;

	k = count / 2;

	printf("Merging [%d/%d] (%s):\n", count, maxsize, dirctn ? "UP" : "DOWN");
	print_array(array + low_idx, count);

	sort_bitonic(array, low_idx, k, maxsize, 1);
	sort_bitonic(array, low_idx + k, k, maxsize, 0);

	bitonic_merge(array, low_idx, count, dirctn);

	printf("Result [%d/%d] (%s):\n", count, maxsize, dirctn ? "UP" : "DOWN");
	print_array(array + low_idx, count);
}

/**
 * bitonic_merge - Merges two bitonic sequences.
 * @array: The array to be sorted.
 * @low_idx: The lowest index of the array or subarray
 * that we are working with.
 * @count: The number of elements in the array or subarray that
 * we are working with.
 * @dirctn: Determines if we are to sort the list in ascending
 * or descending order:
 * 1 - Sort in ascending order.
 * 0 - Sort in descending order.
 */
void bitonic_merge(int *array, int low_idx, int count, int dirctn)
{
	int k, i, temp;
	int *subarray = array + low_idx;

	if (count == 1)
		return;

	k = count / 2;
	for (i = 0; i < k; i++)
	{
		if (dirctn == (subarray[i] > subarray[i + k]))
		{
			temp = subarray[i];
			subarray[i] = subarray[i + k];
			subarray[i + k] = temp;
			print_array(array + low_idx, count);
		}
	}

	bitonic_merge(array, low_idx, k, dirctn);
	bitonic_merge(array, low_idx + k, k, dirctn);
}
