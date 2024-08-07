#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 * Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t j;
	size_t temp;
	size_t i;

	if (size <= 1)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{

				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
