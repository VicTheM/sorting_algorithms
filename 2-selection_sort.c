#include "sort.h"

/**
 * faviswap_ints - swaps integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void faviswap_ints(int *a, int *b)
{
	int temp_value;

	temp_value = *a;
	*a = *b;
	*b = temp_value;
}
/**
 * selection_sort - sorts integers in an array from the smallest to the biggest
 * @array: An array containing integers
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	int *current_min_ptr;
	size_t current_index, inner_index;

	if (array == NULL || size < 2)
		return;

	for (current_index = 0; current_index < size - 1; current_index++)
	{
		current_min_ptr = array + current_index;

		for (inner_index = current_index + 1; inner_index < size; inner_index++)
		current_min_ptr = (array[inner_index] < *current_min_ptr) ?
			(array + inner_index) : current_min_ptr;

		if ((array + current_index) != current_min_ptr)
		{
		faviswap_ints(array + current_index, current_min_ptr);
		print_array(array, size);
		}
	}
}
