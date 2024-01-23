#include "deck.h"

/**
 * compare_strings - To compare two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: if str1 > str2, 0 if str1 == str2, - if str1 < str2.
 */

int compare_strings(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
	str1++;
	str2++;
	}

	if (*str1 != *str2)
	return (*str1 - *str2);
	return (0);
}

/**
 * get_card_value - Returns the numerical value of the card
 * @deckCard: Pointer to a deck card
 * Return: the card value
 */


char get_card_value(deck_node_t *deckCard)
{
	if (compare_strings(deckCard->card->value, "Ace") == 0)
	return (0);
	if (compare_strings(deckCard->card->value, "1") == 0)
	return (1);
	if (compare_strings(deckCard->card->value, "2") == 0)
	return (2);
	if (compare_strings(deckCard->card->value, "3") == 0)
	return (3);
	if (compare_strings(deckCard->card->value, "4") == 0)
	return (4);
	if (compare_strings(deckCard->card->value, "5") == 0)
	return (5);
	if (compare_strings(deckCard->card->value, "6") == 0)
	return (6);
	if (compare_strings(deckCard->card->value, "7") == 0)
	return (7);
	if (compare_strings(deckCard->card->value, "8") == 0)
	return (8);
	if (compare_strings(deckCard->card->value, "9") == 0)
	return (9);
	if (compare_strings(deckCard->card->value, "10") == 0)
	return (10);
	if (compare_strings(deckCard->card->value, "Jack") == 0)
	return (11);
	if (compare_strings(deckCard->card->value, "Queen") == 0)
	return (12);
	return (13);
}

/**
 * sort_deck_by_kind - sorts a deck of cards by suits
 * @deck: pointer to the head of a deck node list
 */

void sort_deck_by_kind(deck_node_t **deck)
{
	deck_node_t *currentCard, *insertPosition, *nextCard;

	for (currentCard = (*deck)->next; currentCard != NULL; currentCard = nextCard)
	{
	nextCard = currentCard->next;
	insertPosition = currentCard->prev;
	while (insertPosition != NULL && insertPosition->card->kind >
			currentCard->card->kind)
	{
		insertPosition->next = currentCard->next;
		if (currentCard->next != NULL)
			currentCard->next->prev = insertPosition;
		currentCard->prev = insertPosition->prev;
		currentCard->next = insertPosition;
		if (insertPosition->prev != NULL)
			insertPosition->prev->next = currentCard;
		else
			*deck = currentCard;
		insertPosition->prev = currentCard;
		insertPosition = currentCard->prev;
	}
	}
}


/**
 * sort_deck_by_value - sorts deck of cards by value within each suit
 * @deck: pointer to the head of a deck_node_t list
 */

void sort_deck_by_value(deck_node_t **deck)
{
	deck_node_t *currentCard, *insertPosition, *nextCard;

	for (currentCard = (*deck)->next; currentCard != NULL; currentCard = nextCard)
	{
	nextCard = currentCard->next;
	insertPosition = currentCard->prev;
	while (insertPosition != NULL &&
			insertPosition->card->kind == currentCard->card->kind &&
			get_card_value(insertPosition) > get_card_value(currentCard))
	{
		insertPosition->next = currentCard->next;
		if (currentCard->next != NULL)
			currentCard->next->prev = insertPosition;
		currentCard->prev = insertPosition->prev;
		currentCard->next = insertPosition;
		if (insertPosition->prev != NULL)
			insertPosition->prev->next = currentCard;
		else
			*deck = currentCard;
		insertPosition->prev = currentCard;
		insertPosition = currentCard->prev;
	}
	}
	}


/**
 * sort_deck - The entry point for sorting the entire deck.
 * Also sorts a deck of cards by suits and value
 * @deck: pointer to the head of a deck_node_t list
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
	return;

	sort_deck_by_kind(deck);
	sort_deck_by_value(deck);
}

