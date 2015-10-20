#pragma once
#include "Deck.h"

#define MAX_CARDS_PER_PLAYER 11 //  4 aces, 4 2s and 3 3s

typedef struct Participant
{
	Card cards[MAX_CARDS_PER_PLAYER];
	char aceTable[NumberOfColors];
	char overallScore;
	char score;
	char numberOfCards;
	bool isDone;
} Participant;

Participant InitParticipant(Deck*);
void InitAceTable(char aceTable[]);

void CalculateScore(Participant*);
void SetCurrentAcesToLow(Participant*);
void CalculateScoreForNonAces(Participant*);
void AdjustAcesValues(Participant*);