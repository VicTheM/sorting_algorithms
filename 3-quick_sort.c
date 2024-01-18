#include "sort.h"

/**
 * swap - swaps two numbers in place
 * @a: address of first number
 * @b: address of second number
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


/**
 * partition: divides the array appopraitely
 * @arr: .......
 * @size: ........
 * @low: starting index of array
 * @high: ending index of array
 *
 * Return: the index of the neutral point
 * 	ie: all elements below this index are less
 * 	than the element in the index, and likewise
 * 	those above are greater than this element
 */
int partition(int *arr, size_t size, int low, int high)
{
	int j;
	int pivot = arr[high];
	int i = (low - 1);

	for (j = low; j < high; j++)
	{
		/* If current element is smaller than or equal to pivot */
		if (arr[j] <= pivot)
		{
            		i++;
			swap(&arr[i], &arr[j]);
            		if (arr[i] != arr[j])
				print_array(arr, size);
        	}
    	}

    	swap(&arr[i + 1], &arr[high]);
    	if (arr[i + 1] != arr[high])
		print_array(arr, size);
    	return (i + 1);
}



/**
 * recursive_call - used to implement partitionning recursively
 * @array: ..........
 * @size: ...........
 * @low: array lower index
 * @high: array higher index
 */
void recursive_call(int *arr, size_t size, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, size, low, high);
        recursive_call(arr, size, low, pi - 1);
        recursive_call(arr, size, pi + 1, high);
    }
}



/**
 * quick_sort - performs quick_sort using Lomuto partitioning Scheme
 * @array: array containing comparable objects
 * @size: Len of array
 */
void quick_sort(int *array, size_t size)
{
	recursive_call(array, size, 0, size - 1);
}


