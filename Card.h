#pragma once

typedef enum Color
{
	Spade,
	Club,
	Heart,
	Diamond,
	NumberOfColors
} Color;

typedef enum Face
{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	NumberOfFaces
} Face;

typedef struct Card
{
	Color color;
	Face face;
} Card;

Color GetRandomColor();
Face GetRandomFace();

char GetColorAsChar(Color color);
char GetFaceAsChar(Face face);

char PointsFor(Card);