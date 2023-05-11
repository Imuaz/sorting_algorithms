#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;

	/*Check if the array is empty or only has one element*/
	if (array == NULL || size < 2)
		return;

	/*
	 * Loop through the array len times, where len starts at the size of the
	 * array
	 */
	while (len--)
	{
		/*Loop through the array up to len-1*/
		for (i = 0; i < len; i++)
		{
			/*Swap elements if they are in the wrong order*/
			if (array[i] > array[i + 1])
			{
				/*Swap two elements using XOR*/
				array[i] ^= array[i + 1];
				array[i + 1] ^= array[i];
				array[i] ^= array[i + 1];
				/*Print the array after each swap*/
				print_array(array, size);
			}
		}
	}
}

