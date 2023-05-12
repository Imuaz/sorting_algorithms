#include "sort.h"


/**
 * int_swp - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void int_swp(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bit_mrg - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bit_mrg(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
			{
				int_swp(&array[i], &array[i + jump]);
				printf("Result [%lu/%lu] (%s):\n", seq, size, flow == UP ? "UP" : "DOWN");
				print_array(array, size);
			}
		}
		bit_mrg(array, size, start, jump, flow);
		bit_mrg(array, size, start + jump, jump, flow);
	}
}

/**
 * bit_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bit_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;

	if (seq > 1)
	{
		bit_seq(array, size, start, cut, UP);
		bit_seq(array, size, start + cut, cut, DOWN);
		bit_mrg(array, size, start, seq, flow);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bit_seq(array, size, 0, size, UP);
}
