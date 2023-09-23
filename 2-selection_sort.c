#include "sort.h"
#include <stddef.h>

/**
 * selection_sort - sort the array using selection sort
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}

}
