#include "Piece.h"

Piece::Piece(std::string place, char color)
{
	this->place = place;
	this->typeAndColor = color;
}

Piece::~Piece()
{
}

char Piece::getColor() const
{
	if (isupper(this->typeAndColor))
	{
		return 'w';
	}
	return 'b';
}

char Piece::getName() const
{
	return this->typeAndColor;
}

std::string Piece::getPlace() const
{
	return this->place;
}
