#include "sort.h"

/**
 * merge_sort - sorting an array of integers from the smallest to the biggest
 * using the Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
*/

void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_rec(array, size, temp);
	free(temp);
}

/**
 * merge_sort_rec - sorts an array of integers from the smallest
 * to the biggest using the  Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @temp: tmp array
 * Return: void
*/

void merge_sort_rec(int *array, size_t size, int *temp)
{
	size_t mid = 0;

	if (size < 2)
		return;

	mid = size / 2;
	merge_sort_rec(array, mid, temp);
	merge_sort_rec(array + mid, size - mid, temp);
	merge(array, size, mid, temp);
}

/**
 * merge - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @mid: mid of the array
 * @tmp: tmp array
 * Return: void
*/

void merge(int *array, size_t size, size_t mid, int *tmp)
{
	size_t i = 0, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);

	while (i < mid && j < size)
	{
		if (array[i] < array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}

	while (i < mid)
		tmp[k++] = array[i++];

	while (j < size)
		tmp[k++] = array[j++];

	for (i = 0; i < size; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(tmp, size);
}
