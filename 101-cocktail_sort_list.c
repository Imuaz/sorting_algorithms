#include "sort.h"

/**
 * swapNodes - Swaps two adjacent nodes in a doubly linked list.
 *
 * @left_node: Pointer to the left node.
 * @right_node: Pointer to the right node.
 * @head: Double pointer to the head of the list.
 */
void swapNodes(listint_t *left_node, listint_t *right_node, listint_t **head)
{
	listint_t *temp_prev = left_node->prev;
	listint_t *temp_next = right_node->next;

	if (temp_prev)
		temp_prev->next = right_node;
	else
		*head = right_node;

	if (temp_next)
		temp_next->prev = left_node;

	right_node->prev = temp_prev;
	right_node->next = left_node;
	left_node->prev = right_node;
	left_node->next = temp_next;

	print_list(*head);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail
 * Shaker sort algorithm.
 *
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current, *tail;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	tail = NULL;

	while (swapped)
	{
		swapped = 0;
		while (current->next != tail)
		{
			if (current->n > current->next->n)
			{
				swapNodes(current, current->next, list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		tail = current;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swapNodes(current->prev, current, list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
