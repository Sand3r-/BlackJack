#include "Participant.h"
#include "Deck.h"

#define LOW_INITIALIZED_ACE -1
#define BLANK_CARD 0

Participant InitParticipant(Deck* deck)
{
	Participant participant;
	participant.score = 0;
	participant.overallScore = 0;
	participant.isDone = false;
	participant.numberOfCards = 2;
	DrawTwoCards(participant.cards, deck);
	InitAceTable(participant.aceTable);

	return participant;
}

void InitAceTable(char aceTable[])
{
	for (int i = 0; i < NumberOfColors; i++)
	{
		aceTable[i] = BLANK_CARD;
	}
}

void CalculateScore(Participant* participant)
{
	participant->score = 0;

	SetCurrentAcesToLow(participant);
	CalculateScoreForNonAces(participant);
	AdjustAcesValues(participant);
}

void SetCurrentAcesToLow(Participant* participant)
{
	for (int i = 0; i < NumberOfColors; i++)
	{
		if ((participant->aceTable[i] == 11))
		{
			participant->aceTable[i] = LOW_INITIALIZED_ACE;
		}
	}
}

void CalculateScoreForNonAces(Participant* participant)
{
	for (int i = 0; i < participant->numberOfCards; i++)
	{
		if (participant->cards[i].face == Ace)
		{
			participant->aceTable[participant->cards[i].color] = LOW_INITIALIZED_ACE;
			participant->score += 1;
		}
		else
		{
			participant->score += PointsFor(participant->cards[i]);
		}
	}
}

void AdjustAcesValues(Participant* participant)
{
	const char aim = 21;
	for (int i = 0; i < NumberOfColors; i++)
	{
		if ((aim - participant->score) < 10) break;

		if (participant->aceTable[i] == LOW_INITIALIZED_ACE)
		{
			participant->aceTable[i] = 11;
			participant->score += 10;
		}
	}
}