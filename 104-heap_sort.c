#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
*/

void heap_sort(int *array, size_t size)
{
	size_t index;
	int temp;

	if (size < 2)
		return;
	
	for (index = size / 2 - 1; (int)index >= 0; index--)
		sift_down(array, size, index, size);
	for (index = size - 1; index > 0; index--)
	{
		temp = array[0];
		array[0] = array[index];
		array[index] = temp;
		print_array(array, size);
		sift_down(array, index, 0, size);
	}
}


/**
 * sift_down - sifts down the element to maintain the heap property
 * @arr: array to sort
 * @size: size of the array
 * @i: index
 * @size2: size of the array
 * Return: void
*/

void sift_down(int *array, size_t size, size_t index, size_t size2)
{
	size_t largest = index;
	size_t left_child = 2 * index + 1;
	size_t right_child = 2 * index + 2;
	int temp;

	if (left_child < size && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != index)
	{
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
	
		print_array(array, size2);
	
		sift_down(array, size, largest, size2);
	}
}

