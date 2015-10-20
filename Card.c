#include "Card.h"
#include <stdlib.h>

Color GetRandomColor()
{
	return (Color)(rand() % NumberOfColors);
}

Face GetRandomFace()
{
	return (Face)(rand() % NumberOfFaces);
}

char GetColorAsChar(Color color)
{
	switch (color)
	{
	case Spade:
		return 'S';
		break;
	case Heart:
		return 'H';
		break;
	case Club:
		return 'C';
		break;
	case Diamond:
		return 'D';
		break;
	default:
		return 'X';
		break;
	}
}

char GetFaceAsChar(Face face)
{
	switch (face)
	{
	case Ace:
		return 'A';
		break;
	case Two:
		return '2';
		break;
	case Three:
		return '3';
		break;
	case Four:
		return '4';
		break;
	case Five:
		return '5';
		break;
	case Six:
		return '6';
		break;
	case Seven:
		return '7';
		break;
	case Eight:
		return '8';
		break;
	case Nine:
		return '9';
		break;
	case Ten:
		return '0';
		break;
	case Jack:
		return 'J';
		break;
	case Queen:
		return 'Q';
		break;
	case King:
		return 'K';
		break;
	default:
		return 'X';
		break;
	}
}

char PointsFor(Card card)
{
	switch (card.face)
	{
	case Two:
		return 2;
		break;
	case Three:
		return 3;
		break;
	case Four:
		return 4;
		break;
	case Five:
		return 5;
		break;
	case Six:
		return 6;
		break;
	case Seven:
		return 7;
		break;
	case Eight:
		return 8;
		break;
	case Nine:
		return 9;
		break;
	case Ten:
		return 10;
		break;
	case Jack:
		return 10;
		break;
	case Queen:
		return 10;
		break;
	case King:
		return 10;
		break;
	default:
		printf("Wrong face provided");
		return 0;
		break;
	}
}