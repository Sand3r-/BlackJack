#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Game.h"

//helper functions
void RngInit();

int main()
{
	RngInit();
	Game game;

	InitGame(&game);
	GameLoop(&game);

	return 0;
}

void RngInit()
{
	srand(time(NULL));
}