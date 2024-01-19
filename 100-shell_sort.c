#include "sort.h"

/**
 * faviswap_ints - Swaps integers in an array
 * @a: first integer
 * @b: second integer
 */

void faviswap_ints(int *a, int *b)
{
	int temp_value;

	temp_value = *a;
	*a = *b;
	*b = temp_value;
}
/**
 * shell_sort - Sorry arrays of integers from the
 * smallest to the biggest using the shell
 * sort alogrithm
 * @array: Array of integers
 * @size: size of the arra
 */

void shell_sort(int *array, size_t size)
{
	size_t interval, currentIndex, innerIndex;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (currentIndex = interval; currentIndex < size; currentIndex++)
		{
			innerIndex = currentIndex;
		while (innerIndex >= interval && array[innerIndex - interval] >
				array[innerIndex])
		{
			faviswap_ints(array + innerIndex, array + (innerIndex - interval));
		innerIndex -= interval;
	}
}
	print_array(array, size);
}
}
