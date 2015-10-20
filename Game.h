#pragma once
#include "Participant.h"
#include "Deck.h"

typedef enum Winner
{
	Nobody,
	Player,
	Croupier
} Winner;
 
typedef struct Game
{
	Participant player;
	Participant croupier;
	Deck deck;
	Winner winner;
	bool finished;
} Game;

void GameLoop(Game*);
void InitGame(Game*);
void Render(Game*);
void Update(Game*);
void ProcessInput(Game*);

//helper functions
void HitOrStand();
void CalculateResults(Game*);
void DetermineWinner(Game*);
void ResetGameIfFinished(Game*);
void ShowScores(Game*);
void ShowCards(Game*);
void ShowWinnerIfFinished(Game*);
void ShowScoreBoard(Game*);
void DrawCardFor(Participant*, Deck*);
void Hit(Game*);
void Stand(Game*);
void PlayerWins(Game*);
void CroupierWins(Game*);

char* GetScoreAsString(char);
char ReadInput();