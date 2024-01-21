#include "sort.h"
#include <stdio.h>


/**
 * copy_arr - copies an array
 * @a: source;
 * @b: destination;
 * @start: a beginning index
 * @end: a end index
 */
void copy_arr(int *a, int *b, int start, int end)
{
	int c = start;

	for (c = 0; c < end; c++)
		b[c] = a[c];
}

void merge_array(int *b, int start, int middle, int end, int *a)
{
	int k, i = start;
	int j = middle;


	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || a[i] <= a[j]))
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
		}
	}
}

void split_recursive(int *b, int start, int end, int *a)
{
	int mid;

	/* Elements are now singletons */
	if (end - start <= 1)
		return;

	mid = (start + end) / 2;
	split_recursive(a, start, mid, b);
	split_recursive(a, mid, end, b);
	printf("**************merging******************\n");
	printf("[left]: ");
	print_array(a, end - start);
	printf("[right]: ");

	merge_array(b, start, mid, end, a);
	print_array(a + start, end - start);
}



/**
 * merge_sort - A super speed efficient sorting algorithm
 * @array: array to sort
 * @size: size of array
 * category; Recursive and non memory efficient
 *
 * Description: Recursively splits an array in half till all
 * elements are singletons, the its starts merging the arrays
 * in a sorted order
 *
 * Top down implementation
 */
void merge_sort(int *array, size_t size)
{
	int *b;

	if (size < 2)
		return;
	
	b = malloc(sizeof(int) * size);
	if (!b)
		return;

	copy_arr(array, b, 0, size);
	split_recursive(array, 0, size, b);

	free (b);
}
