#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list using the cocktail shaker
 *
 * @list: A pointer to a pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *runner;

	if (!list)
		return;

	runner = *list;
	while (swapped)
	{
		swapped = 0;
		while (runner->next)
		{
			if (runner->n > runner->next->n)
			{
				swap_nodes(list, runner, runner->next);
				swapped = 1;
				print_list(*list);
			}
			else
				runner = runner->next;
		}
		if (!swapped)
			return;
		swapped = 0;
		while (runner->prev)
		{
			if (runner->n < runner->prev->n)
			{
				swap_nodes(list, runner->prev, runner);
				swapped = 1;
				print_list(*list);
			}
			else
				runner = runner->prev;
		}
	}
}
