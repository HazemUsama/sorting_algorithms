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
			curr_node->prev = prev_node->prev;
			prev_node->next = curr_node->next;
			if (curr_node->next)
				curr_node->next->prev = prev_node;

			curr_node->next = prev_node;
			if (prev_node->prev)
				prev_node->prev->next = curr_node;
			else
				*list = curr_node;

			prev_node->prev = curr_node;
			prev_node = curr_node->prev;
			cnt++;
			print_list(*list);
		}

		while (cnt--)
			curr_node = curr_node->next;

		curr_node = curr_node->next;
	}
}
