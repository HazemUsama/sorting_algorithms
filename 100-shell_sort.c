#include "sort.h"

/**
 * shell_sort - Sorts an integer array in ascending order using Shell sort.
 *
 * @array: Pointer to the integer array to be sorted.
 * @size: Number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t cnt = 1, gaps_cnt = 0, *gaps;
	size_t i, j, k;

	while (cnt < size)
	{
		cnt = cnt * 3 + 1;
		gaps_cnt++;
	}

	gaps = malloc(sizeof(size_t) * gaps_cnt);
	if (!gaps)
		return;

	gaps[0] = 1;
	for (i = 1; i < gaps_cnt; i++)
		gaps[i] = gaps[i - 1] * 3 + 1;
	i = gaps_cnt - 1;
	while (1)
	{
		for (j = gaps[i]; j < size; j++)
		{
			tmp = array[j];
			for (k = j; (k >= gaps[i]) && (array[k - gaps[i]] > tmp); k -= gaps[i])
				array[k] = array[k - gaps[i]];

			array[k] = tmp;
		}
		print_array(array, size);
		if (gaps[i] == 1)
			break;
		i--;
	}
	free(gaps);
}
