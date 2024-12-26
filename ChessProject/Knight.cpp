#include "Knight.h"

Knight::Knight(std::string place, char color) : Piece(place, color)
{
	
}

Knight::~Knight(){

}

int Knight::move(std::string& places)
{
	std::string targetSquare = std::to_string(places[2]) + std::to_string(places[3]);
	this->place = targetSquare;
	return 0;
}

int Knight::isTheMoveLegal(std::string& places, Piece* board[8][8])
{
	std::string rooksPosition = std::to_string(places[0]) + std::to_string(place[1]); // Extract the current rooks position
	std::string targetSquare = std::to_string(places[2]) + std::to_string(place[3]);
	int currentCol = rooksPosition[0] - 'a'; // Convert from chess moves to array indexes
	int currentRow = std::abs(rooksPosition[1] - '8');
	int targetCol = targetSquare[0] - 'a';
	int targetRow = std::abs(targetSquare[1] - '8');
	if ((std::abs(currentRow - targetRow) != 1 && std::abs(currentRow - targetRow) != 2) ||
		(std::abs(currentCol - targetCol) != 1 && std::abs(currentCol - targetCol) != 2))
	{
		return 6;
	}
	return 0;
}
