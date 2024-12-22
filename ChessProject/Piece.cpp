#include "Piece.h"

Piece::Piece(std::string place, char color)
{
	this->place = place;
	this->typeAndColor = color;
}

Piece::~Piece()
{
}

char Piece::getName()
{
	return this->typeAndColor;
}
