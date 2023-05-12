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
 * bitonic_mrg - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 *
 * Des: Performs bitonic merge on the given sequence.
 */
void bitonic_mrg(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t i, jump;

	if (seq <= 1)
		return;

	jump = seq / 2;

	for (i = start; i < start + jump; i++)
	{
		if ((flow == UP && array[i] > array[i + jump]) ||
		    (flow == DOWN && array[i] < array[i + jump]))
		{
			swap_ints(array + i, array + i + jump);
			print_array(array, size);
		}
	}

	bitonic_mrg(array, size, start, jump, flow);
	bitonic_mrg(array, size, start + jump, jump, flow);
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 *
 * Des: Recursively divides the array into bitonic sequences
 * and performs bitonic merge on them.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut;
	const char *str;

	if (seq <= 1)
		return;

	cut = seq / 2;
	str = (flow == UP) ? "UP" : "DOWN";

	printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
	print_array(array + start, seq);

	bitonic_seq(array, size, start, cut, UP);
	bitonic_seq(array, size, start + cut, cut, DOWN);
	bitonic_mrg(array, size, start, seq, flow);

	printf("Result [%lu/%lu] (%s):\n", seq, size, str);
	print_array(array + start, seq);
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 * using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Des: Performs bitonic sort on the given array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
