#include "sort.h"

/**
 * insertion_sort_list - sort a double linked list
 *
 * @list: the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node, *prev_node;
	size_t cnt;

	if (!list)
		return;

	curr_node = *list;
	while (curr_node)
	{
		cnt = 0;
		prev_node = curr_node->prev;
		while (prev_node && curr_node->n < prev_node->n)
		{
			swap_nodes(list, prev_node, curr_node);
			prev_node = curr_node->prev;
			print_list(*list);
			cnt++;
		}

		while (cnt--)
			curr_node = curr_node->next;

		curr_node = curr_node->next;
	}
}
