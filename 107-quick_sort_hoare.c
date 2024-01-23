#include "sort.h"

int partition_2(int *a, int lo, int hi, size_t size);
void swap_2(int *i, int *j);
void hoare(int *array, int lo, int hi, size_t size);


void quick_sort_hoare(int *array, size_t size)
{
	int lo, hi;

	if (size < 2)
		return;

	lo = 0;
	hi = size - 1;

	hoare(array, lo, hi, size);
}


void hoare(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo >= 0 && hi >= 0 && lo < hi)
	{
		pivot = partition_2(array, lo, hi, size);
		hoare(array, lo, pivot, size);
		hoare(array, pivot + 1, hi, size);
	}
}




int partition_2(int *a, int lo, int hi, size_t size)
{
	int bound, i, j;

	bound = a[lo];
	i = lo - 1;
	j = hi + 1;

	while (1)
	{
		do {
			i++;
		} while (a[i] < bound);

		do {
			j--;
		} while (a[j] > bound);

		if (i >= j)
			return (j);

		swap_2(&a[i], &a[j]);
		print_array(a, size);
	}
}


void swap_2(int *i, int *j)
{
	int tmp = *i;

	*i = *j;
	*j = tmp;
}
