#include "sort.h"

/**
 * bubble_sort - bubble sort the array
 *
 * @array: the array
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		if (array[j - 1] > array[j])
		{
			swap(&array[j - 1], &array[j]);
			print_array(array, size);
		}
	}
}
