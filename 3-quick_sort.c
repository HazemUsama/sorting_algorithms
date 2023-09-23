#include "sort.h"

/**
 * quick_sort - quick sort the array
 *
 * @array: the array
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	sort(array, size, 0, size - 1);
}

/**
 * sort - Recursively sorts a subarray using the Quick Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @st: The starting index of the subarray.
 * @nd: The ending index of the subarray.
 */
void sort(int *array, size_t size, size_t st, size_t nd)
{
	size_t p;

	if ((int) st >= (int) nd)
		return;

	p = partition(array, size, st, nd);

	sort(array, size, st, p - 1);
	sort(array, size, p + 1, nd);

}
/**
 * partition - Partitions a subarray for the Quick Sort algorithm.
 *
 * @array: The array to be partitioned.
 * @size: The size of the array.
 * @st: The starting index of the subarray.
 * @nd: The ending index of the subarray.
 *
 * Return: The final position of the pivot element in the array.
 */
size_t partition(int *array, size_t size, size_t st, size_t nd)
{
	size_t i, j;
	int pivot = array[nd];

	i = st - 1;
	for (j = st; j < nd; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i == j)
				continue;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	if (i + 1 < nd)
	{
		swap(&array[i + 1], &array[nd]);
		print_array(array, size);
	}
	return (i + 1);
}

