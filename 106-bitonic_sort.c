#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers from the smallest to the biggest
 * @array: array to sort
 * @size: size of the array
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_sort_rec(array, size, 1, size);
}

/**
 * bitonic_sort_rec - sorts an array of integers
 * from the smallest to the biggest
 * @array: array to sort
 * @size: size of the array
 * @dir: direction of the sort
 * @size_total: size of the array
*/

void bitonic_sort_rec(int *array, size_t size, int dir, size_t size_total)
{
	size_t k = size / 2;

	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, size_total,
	dir == 1 ? "UP" : "DOWN");
	print_array(array, size);
	bitonic_sort_rec(array, k, 1, size_total);
	bitonic_sort_rec(array + k, k, 0, size_total);
	bitonic_merge(array, size, dir, size_total);
	printf("Result [%lu/%lu] (%s):\n", size, size_total,
	dir == 1 ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_merge - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 * @dir: direction of the sort
 * @size_total: size of the array
*/

void bitonic_merge(int *array, size_t size, int dir, size_t size_total)
{
	size_t k = size / 2, i;

	if (size < 2)
		return;
	for (i = 0; i < k; i++)
		if (dir == (array[i] > array[i + k]))
			faviswap(&array[i], &array[i + k]);
	bitonic_merge(array, k, dir, size_total);
	bitonic_merge(array + k, k, dir, size_total);
}

/**
 * faviswap - swaps two integers
 * @a: first integer
 * @b: second integer
*/

void faviswap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
