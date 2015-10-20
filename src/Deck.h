#pragma once
#include "Card.h"
#include <stdbool.h>

#define MAX_CARDS_IN_DECK 52

typedef struct Deck
{
	Card cards[MAX_CARDS_IN_DECK];
} Deck;

Deck CreateDeck();

void DrawTwoCards(Card* cards, Deck* deck);
Card DrawCard(Deck* deck);

//returns true if succeeded
bool RemoveCardIfAvailable(Card, Deck*);