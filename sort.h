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

void sort(int *array, size_t size, size_t st, size_t nd);
size_t partition(int *array, size_t size, size_t st, size_t nd);

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);


#endif
