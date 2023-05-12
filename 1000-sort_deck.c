#include "deck.h"

/**
 * swap_nodes - swaps two nodes in a doubly-linked list.
 *
 * @node1:The first node to swap.
 * @node2:The second node to swap.
 */
void swap_nodes(deck_node_t *node1, deck_node_t *node2)
{
	deck_node_t *prev1 = node1->prev;
	deck_node_t *next1 = node1->next;
	deck_node_t *prev2 = node2->prev;
	deck_node_t *next2 = node2->next;

	if (prev1 != NULL)
	{
		prev1->next = node2;
	}
	node2->prev = prev1;

	if (next1 != NULL)
	{
		next1->prev = node2;
	}
	node2->next = next1;

	if (prev2 != NULL)
	{
		prev2->next = node1;
	}
	node1->prev = prev2;

	if (next2 != NULL)
	{
		next2->prev = node1;
	}
	node1->next = next2;
}

/**
 * _strcmp - compare two strings.
 *
 * @s1:The first string to compare.
 * @s2:The second string to compare.
 * Return: 0 if the strings are equal, a positive value if s1 > s2,
 *        a negative value if s1 < s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * get_value - Get the numerical value of a card.
 *
 * @card:A pointer to a deck_node_t representing a card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
	char i;
	const char *values[] = {
		"Ace", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen"};
	const char *card_value = card->card->value;

	for (i = 0; i < 13; i++)
	{
		if (_strcmp(card_value, values[i]) == 0)
		{
			return (i);
		}
	}

	return (13); /*Default value if card value is not found*/
}

/**
 * insertion_sort_deck_kind - sort a deck of cards from spades to diamonds.
 *
 * @deck:A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	if (*deck == NULL || (*deck)->next == NULL)
	{
		return; /* Nothing to sort*/
	}

	deck_node_t *current = (*deck)->next;

	while (current != NULL)
	{
		deck_node_t *temp = current;

		while (temp != NULL && temp->prev != NULL && temp->prev->card->kind >
				temp->card->kind)
		{
			swap_nodes(temp->prev, temp);
			temp = temp->prev;
		}

		current = current->next;
	}
}

/**
 * insertion_sort_deck_value - sort a deck of cards from ace
 * to king within each kind.
 *
 * @deck:A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	if (*deck == NULL || (*deck)->next == NULL)
	{
		return;  /*Nothing to sort*/
	}
	deck_node_t *current = (*deck)->next;

	while (current != NULL)
	{
		deck_node_t *temp = current;

		while (temp != NULL && temp->prev != NULL && temp->prev->card->kind ==
				temp->card->kind && get_value(temp->prev) > get_value(temp))
		{
			swap_nodes(temp->prev, temp);
			temp = temp->prev;
		}
		current = current->next;
	}
}

/**
 * sort_deck - sort a deck of cards from ace to king and from
 * spades to diamonds.
 *
 * @deck:A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (*deck == NULL || (*deck)->next == NULL)
	{
		return;  /*Nothing to sort*/
	}

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
