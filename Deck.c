#include "Deck.h"

Deck CreateDeck()
{
	Deck deck;
	int counter = 0;

	for (Color color = 0; color < NumberOfColors; color++)
	{
		for (Face face = 0; face < NumberOfFaces; face++)
		{
			Card card = { .color = color,.face = face };
			deck.cards[counter++] = card;
		}
	}

	return deck; //copy of like 104 bytes, idk if this is such an epic idea
}

void DrawTwoCards(Card* cards, Deck* deck)
{
	cards[0] = DrawCard(deck);
	cards[1] = DrawCard(deck);
}

Card DrawCard(Deck* deck)
{
	Card card;
	do
	{
		card.color = GetRandomColor();
		card.face = GetRandomFace();
	} while (!RemoveCardIfAvailable(card, deck));

	return card;
}

bool RemoveCardIfAvailable(Card card, Deck* deck)
{
	for (int i = 0; i < MAX_CARDS_IN_DECK; i++)
	{
		if (deck->cards[i].face == card.face &&
			deck->cards[i].color == card.color)
		{
			deck->cards[i].face = -1; //set to -1 so it can no longer be found
			deck->cards[i].color = -1; //and behaves as if the card was removed from deck
			return true;
		}
	}

	return false; //not available
}