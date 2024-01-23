#include <stdlib.h>
#include "sort.h"

void copy_array(int *src, size_t size, int *dest);
void counting_sortt(int *array, int *buffer, size_t size, int k, int *base);


/**
 * radix_sort - a successor of counting sort
 * @array: array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	size_t c, k;
	int *buffer, *base, max;

	if (size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	base = malloc(sizeof(int) * 10);

	max = array[0];
	/* find max number */
	for (c = 0; c < size; c++)
	{
		buffer[c] = 0;
		if (array[c] >= max)
			max = array[c];
	}

	for (k = 1; max / k > 0; k *= 10)
		counting_sortt(array, buffer, size, k, base);
	free(base);
	free (buffer);
}




/**
 * copy_array - copies one array to another
 * @src: source
 * @size: size of source
 * @dest: destination
 */
void copy_array(int *src, size_t size, int *dest)
{
	size_t i = 0;

	for ( ; i < size; i++)
		dest[i] = src[i];
}



/**
 * counting_sortt - implements counting sort on each of radix digit
 * @array: array to sort
 * @buffer: same size as @array
 * @size: their size
 * @k: used to determine which placeValue to sort by
 * @base: an array of 10 slots
 */
void counting_sortt(int *array, int *buffer, size_t size, int k, int *base)
{
	size_t c;
	int digit, idx, j;
	{
		for (c = 0; c < 10; c++)
		{
			buffer[c] = 0;
			base[c] = 0;
		}
		/* populate reference array */
		for (c = 0; c < size; c++)
		{
			base[(array[c] / k) % 10]++;
		}
		/* populate lookup array with the sum */
		for (j = 0; j < 9; j++)
			base[j + 1] += base[j];

		/* sort into a buffer */
		for (j = size - 1; j >= 0; j--)
		{
			digit = array[j];
			idx = base[(digit / k) % 10] - 1;
			buffer[idx] = digit;
			base[(digit / k) % 10]--;
		}
		print_array(buffer, size);
		copy_array(buffer, size, array);
	}
}
