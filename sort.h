#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * swap - swap two numbers
 *
 * @a: pointer to the first number
 * @b: pointer to the second number
 */
static inline void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 *
 * @head: Pointer to the pointer to the head of the linked list.
 * @curr_node: Pointer to the node to be swapped with the previous node.
 * @prev_node: Pointer to the previous node in the list.
 *
 */
static inline void swap_nodes
	(listint_t **head, listint_t *prev_node, listint_t *curr_node)
{

	curr_node->prev = prev_node->prev;
	prev_node->next = curr_node->next;
	if (curr_node->next)
		curr_node->next->prev = prev_node;

	curr_node->next = prev_node;
	if (prev_node->prev)
		prev_node->prev->next = curr_node;
	else
		*head = curr_node;

	prev_node->prev = curr_node;

}
void sort(int *array, size_t size, size_t st, size_t nd);
size_t partition(int *array, size_t size, size_t st, size_t nd);

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
