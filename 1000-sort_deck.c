#include <string.h>
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
		prev1->next = node2;
	if (next1 != NULL)
		next1->prev = node2;
	if (prev2 != NULL)
		prev2->next = node1;
	if (next2 != NULL)
		next2->prev = node1;

	node1->prev = prev2;
	node1->next = next2;
	node2->prev = prev1;
	node2->next = next1;
}

/**
 * get_value - Get the numerical value of a card.
 *
 * @card: A pointer to a deck_node_t representing a card.
 *
 * Return: The numerical value of the card.
 */
int get_value(deck_node_t *card)
{
	int i;
	const char *values[] = {
		"Ace",
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
		"Jack",
		"Queen"
	};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(card->card->value, values[i]) == 0)
		{
			return (i);
		}
	}

	return (13); /* Default value if card value is not found */
}

/**
 * sort_deck - sort a deck of cards from ace to king and from
 * spades to diamonds.
 *
 * @deck:A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;

	if (*deck == NULL || (*deck)->next == NULL)
	{
		return; /* Nothing to sort */
	}
	current = (*deck)->next;

	while (current != NULL)
	{
		deck_node_t *temp = current;

		while (temp != NULL && temp->prev != NULL &&
				temp->prev->card->kind == temp->card->kind &&
				get_value(temp->prev) > get_value(temp))
		{
			swap_nodes(temp->prev, temp);
			temp = temp->prev;
		}
		current = current->next;
	}
}
