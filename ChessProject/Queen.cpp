#include "Queen.h"

Queen::Queen(std::string place, char color) : Bishop(place, color) , Rook(place,color)
{

}

Queen::~Queen()
{
}

int Queen::isTheMoveLegal(std::string& places, Piece* board[8][8])
{
	if (Rook::isTheMoveLegal(places, board) != 0 && Bishop::isTheMoveLegal(places, board) != 0)
	{
		return 6;
	}
	return 0;
}

int Queen::move(std::string& move)
{
	Bishop::move(move);
	return 0;
}
