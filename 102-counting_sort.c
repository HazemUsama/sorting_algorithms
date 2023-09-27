#include "sort.h"


/**
 * counting_sort - Sorts an integer array using Counting sort.
 *
 * @array: Pointer to the integer array to be sorted.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int max_elem = 0, *counting_array, *new_array;
	size_t i;

	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		if (max_elem < array[i])
			max_elem = array[i];
	}
	counting_array = malloc(sizeof(int) * (max_elem + 1));
	new_array = malloc(sizeof(int) * size);
	if (!counting_array)
		return;
	if (!new_array)
	{
		free(counting_array);
		return;
	}

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	for (i = 1; i <= (size_t) max_elem; i++)
		counting_array[i] += counting_array[i - 1];

	print_array(counting_array, max_elem + 1);

	for (i = size - 1; (int) i >= 0; i--)
	{
		new_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = new_array[i];

	free(counting_array);
	free(new_array);
}
