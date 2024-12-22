#include "King.h"
King::King(std::string place, char color) : Piece(place, color)
{
	
}

King::~King()
{
}

int King::isTheMoveLegal(std::string& places, Piece* board[8][8])
{
	std::string rooksPosition = std::to_string(places[0]) + std::to_string(place[1]); // Extract the current rooks position
	std::string targetSquare = std::to_string(places[2]) + std::to_string(place[3]);
	int currentCol = rooksPosition[0] - 'a'; // Convert from chess moves to array indexes
	int currentRow = std::abs(rooksPosition[1] - '8');
	int targetCol = targetSquare[0] - 'a';
	int targetRow = std::abs(targetSquare[1] - '8');
	if (std::abs(currentCol - targetCol) > 1 || std::abs(currentRow - targetRow) > 1)
	{
		return 6;
	}
	return 0;
}

int King::move(std::string& move)
{
	std::string targetSquare = std::to_string(move[2]) + std::to_string(move[3]);
	this->place = targetSquare;
	// Still have to check if player is check so we can return the correct code but for now we will just return 0
	return 0;
}
