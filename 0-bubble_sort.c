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
	int tmp;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		if (array[j - 1] > array[j])
		{
			tmp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = tmp;
			print_array(array, size);
		}
	}
}
