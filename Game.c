#include "Game.h"
#include <stdbool.h>
#include <stdio.h>

void InitGame(Game* game)
{
	game->deck = CreateDeck();
	game->player = InitParticipant(&game->deck);
	game->croupier = InitParticipant(&game->deck);
	game->winner = Nobody;
	game->finished = false;

	CalculateResults(game);
}

void GameLoop(Game* game)
{
	while (true)
	{
		Render(game);
		Update(game);
	}
}

void Render(Game* game)
{
	ShowCards(game);
	ShowScores(game);
	ShowWinnerIfFinished(game);
}

void Update(Game* game)
{
	ResetGameIfFinished(game);
	HitOrStand();
	ProcessInput(game);
	CalculateResults(game);
	DetermineWinner(game);
}

void ProcessInput(Game* game)
{
	switch (ReadInput())
	{
	case 'H':
	case 'h':
		Hit(game);
		break;
	case 'S':
	case 's':
		Stand(game);
		break;
	default:
		printf("Wrong, please choose (h)it or (s)tand\n");
		break;
	}
}

char ReadInput()
{
	char input = getchar();
	fseek(stdin, 0, SEEK_END); //flush buffer
	return input;
}

void CalculateResults(Game* game)
{
	CalculateScore(&game->player);
	CalculateScore(&game->croupier);
}

void DetermineWinner(Game* game)
{
	char limit = 21;
	
	if (game->croupier.score == limit)
		CroupierWins(game);

	else if (game->player.score == limit)
		PlayerWins(game);

	if (game->player.score > limit)
		CroupierWins(game);

	else if (game->croupier.score > limit)
		PlayerWins(game);

	else if (game->croupier.isDone && game->player.isDone)
	{
		//Tie is accounted for Croupier's win
		if (game->croupier.score >= game->player.score)
			CroupierWins(game);
		else
			PlayerWins(game);
	}
}

void ResetGameIfFinished(Game* game)
{
	if (game->finished)
	{
		char croupierScore = game->croupier.overallScore;
		char playerScore = game->player.overallScore;

		InitGame(game);

		game->croupier.overallScore = croupierScore;
		game->player.overallScore = playerScore;

		//these 2 are kinda hacky, but w/e -,-
		Render(game);
	}
}

void ShowCards(Game* game)
{
	printf("Player:\n");
	ShowCardsFrom(game->player);
	printf("Croupier:\n");
	ShowCardsFrom(game->croupier);
}

void ShowScores(Game* game)
{
	char* playerScore = GetScoreAsString(game->player.score);
	char* croupierScore = GetScoreAsString(game->croupier.score);

	printf("Players score: ");
	printf(playerScore);
	printf("\nCroupiers score: ");
	printf(croupierScore);
	printf("\n");

	free(playerScore);
	free(croupierScore);
}

void ShowWinnerIfFinished(Game* game)
{
	if (game->winner == Croupier)
		printf("-Croupier- has won\n\n");
	else if (game->winner == Player)
		printf("+Player+ has won!\n\n");

	if (game->winner != Nobody)
		ShowScoreBoard(game);
}

void ShowScoreBoard(Game* game)
{
	printf("### Player: %d | Croupier: %d ###\n\n", game->player.overallScore, game->croupier.overallScore);
}

void Hit(Game* game)
{
	DrawCardFor(&game->player, &game->deck);
}

void Stand(Game* game)
{
	//There should be some AI stuff in here actually
	//but for now let's assume that croupier is 
	//just doing 1 move if player chooses stand no matter what
	DrawCardFor(&game->croupier, &game->deck);
	game->player.isDone = true;
	game->croupier.isDone = true;
}

void PlayerWins(Game* game)
{
	game->winner = Player;
	game->player.overallScore++;
	game->finished = true;
}

void CroupierWins(Game* game)
{
	game->winner = Croupier;
	game->croupier.overallScore++; //jk?
	game->finished = true;
}

void HitOrStand()
{
	printf("Do you (h)it or (s)tand?\n");
}

void DrawCardFor(Participant* participant, Deck* deck)
{
	char numberOfCards = participant->numberOfCards++;
	participant->cards[numberOfCards] = DrawCard(deck);
}

char* GetScoreAsString(char score)
{
	char* scoreString = malloc(sizeof(char) * 3);

	if (score > 9)
	{
		scoreString[0] = (score / 10) + 48;
		scoreString[1] = (score % 10) + 48;
		scoreString[2] = '\0';
	}
	else
	{
		scoreString[0] = (score % 10) + 48;
		scoreString[1] = '\0';
	}

	return scoreString;
}