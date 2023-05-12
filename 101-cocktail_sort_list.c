#include "sort.h"

/**
 * swp_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to the head of the doubly linked list.
 * @node1: First node to swap.
 * @node2: Second node to swap.
 */
void swp_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (!node2->prev)
		*list = node2;
	print_list((const listint_t *)*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      using the Cocktail Shaker sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL;
	listint_t *end = NULL;
	listint_t *current = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		for (current = start = *list; current->next != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swp_nodes(list, current, current->next);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		end = current;

		for (current = end; current != start; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swp_nodes(list, current->prev, current);
				swapped = 1;
			}
		}

		start = current;
	}
}
