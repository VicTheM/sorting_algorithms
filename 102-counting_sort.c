#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted_arr, max_value, index;

	if (array == NULL || size < 2)
	return;

	max_value = array[0];
	for (index = 1; index < (int)size; index++)
	if (array[index] > max_value)
	max_value = array[index];
	count = malloc(sizeof(int) * (max_value + 1));
	if (count == NULL)
	return;
	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
	{
	free(count);
	return;
	}
	for (index = 0; index <= max_value; index++)
	count[index] = 0;
	for (index = 0; index < (int)size; index++)
	count[array[index]]++;
	for (index = 1; index <= max_value; index++)
	count[index] += count[index - 1];
	print_array(count, max_value + 1);
	for (index = 0; index < (int)size; index++)
	{
	sorted_arr[count[array[index]] - 1] = array[index];
	count[array[index]]--;
	}
	for (index = 0; index < (int)size; index++)
	array[index] = sorted_arr[index];

	free(count);
	free(sorted_arr);
}

