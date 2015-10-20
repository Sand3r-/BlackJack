#include "Renderer.h"
#include <stdio.h>

void ShowCardsFrom(Participant participant) //change to pointer
{
	for (int i = 0; i < participant.numberOfCards; i++)
	{
		ConsoleWriteCard(participant.cards[i]);
	}
	printf("\n");
}

void ConsoleWriteCard(Card card)
{
	char color = GetColorAsChar(card.color);
	char face = GetFaceAsChar(card.face);
	char cardString[3] = { color, face, '\0' };

	printf(cardString);
}