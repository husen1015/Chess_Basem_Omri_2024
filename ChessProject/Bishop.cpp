#include "Bishop.h"

Bishop::Bishop(std::string place, char color) : Piece(place, color)
{

}

Bishop::~Bishop()
{
}

int Bishop::move(std::string& places)
{
	return 0;
}

int Bishop::isTheMoveLegal(std::string& places, Piece* board[8][8])
{
	return 0;
}
