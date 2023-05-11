#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = iter->next)
	{
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			iter->prev = insert->prev;
			insert->next = iter->next;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			insert->prev = iter;
			if (*list == insert)
				*list = iter;
			if (insert->next != NULL)
				insert->next->prev = insert;
			print_list((const listint_t *)*list);
			insert = iter->prev;
		}
	}
}
