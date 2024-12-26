#include "Empty.h"

Empty::Empty(std::string place, char color) : Piece(place, color)
{
		
}

Empty::~Empty()
{
}

int Empty::move(std::string& places)
{
	return 0;
}

int Empty::isTheMoveLegal(std::string& places, Piece* board[8][8])
{
	return 0;
}


