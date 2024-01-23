#include <stdlib.h>
#include "sort.h"

size_t get_digit(int number, int place_Value);
int my_pow(int x, int y);
void copy_array(int *src, size_t size, int *dest);
size_t count_digit(int number);


void radix_sort(int *array, size_t size)
{
	size_t c, j, k, ndigits;
	int *buffer, *base, digit, idx, max;

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

	/* main loop executed for every digit in numbers*/
	ndigits = count_digit(max);
	
	for (k = 0; k < ndigits; k++)
	{
		for (c = 0; c < 10; c++)
			base[c] = 0;
		/* populate reference array */
		for (j = 0; j < size; j++)
		{
			digit = get_digit(array[j], k);
			base[digit]++;
		}
		/* populate lookup array with the sum */
		for (j = 0; j < 9; j++)
			base[j + 1] += base[j];

		/* sort into a buffer */
		for (j = 0; j < size; j++)
		{
			digit = get_digit(array[j], k);
			idx = base[digit] - 1;
			buffer[idx] = array[j];
			base[digit]--;
		}
		print_array(buffer, size);
		copy_array(buffer, size, array);
	}

	free(base);
	free(buffer);
}




int my_pow(int x, int y)
{
	int i;
	int ans = 1;

	for (i = 0; i < y; i++)
		ans *= x;

	return (ans);
}



size_t get_digit(int number, int place_value)
{
	return ((number / (my_pow(10, place_value))) % 10);
}



size_t count_digit(int number)
{
	size_t digits = 1;

	while (number / 10 != 0)
	{
		digits++;
		number /= 10;
	}

	return (digits);
}



void copy_array(int *src, size_t size, int *dest)
{
	size_t i = 0;

	for ( ; i < size; i++)
		dest[i] = src[i];
} 
