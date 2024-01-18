#include "sort.h"

/**
 * faviswap_ints - for swapping two integers in an array
 *
 * @i: first integer to swap
 * @j: second integer to swap
 */

void faviswap_ints(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * bubble_sort - Sorts an array of integers
 * from the smallest to the biggest
 * @array: Array of integers to be sorted
 * @size: Size of an array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int swaps_occurred = 1;

	if (array == NULL || size < 2)
		return;
	while (swaps_occurred)
	{
		swaps_occurred = 0;

		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				faviswap_ints(array + i, array + i + 1);
				print_array(array, size);
				swaps_occurred = 1;
			}
		}
		len--;
	}
}
