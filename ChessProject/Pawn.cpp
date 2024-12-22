#include "Pawn.h"

Pawn::Pawn(std::string place, char color) : Piece(place, color)
{
	this->hasMoved = false;
}

Pawn::~Pawn()
{
}

int Pawn::isTheMoveLegal(std::string& places, Piece* board[8][8])
{
	std::string rooksPosition = std::to_string(places[0]) + std::to_string(place[1]); // Extract the current rooks position
	std::string targetSquare = std::to_string(places[2]) + std::to_string(place[3]);
	int currentCol = rooksPosition[0] - 'a'; // Convert from chess moves to array indexes
	int currentRow = std::abs(rooksPosition[1] - '8');
	int targetCol = targetSquare[0] - 'a';
	int targetRow = std::abs(targetSquare[1] - '8');
	if (targetRow >= currentRow)
	{
		return 6;
	}
	if (!this->hasMoved && std::abs(currentRow - targetRow) > 2)
	{
		return 6;
	}
	if (this->hasMoved && std::abs(currentRow - targetRow) > 1)
	{
		return 6;
	}
	if (currentCol == targetCol)
	{
		if (board[currentRow - 1][currentCol]->getName() != '#')
		{
			return 6;
		}
		if (std::abs(targetRow - currentRow) == 2)
		{
			if (board[currentRow - 2][currentCol]->getName() != '#')
			{
				return 6;
			}
		}
	}
	if (std::abs(currentCol - targetCol) > 1)
	{
		return 6;
	}
	if (std::abs(currentCol - targetCol) == 1 && std::abs(currentRow - targetRow) == 1) {
		if (board[currentRow - 1][currentCol - 1]->getName() == '#' || std::isupper(board[currentRow][currentCol]->getName())
			== std::isupper(board[currentRow - 1][currentCol - 1]->getName()) || board[currentRow - 1][currentCol + 1]->getName() == '#' || std::isupper(board[currentRow][currentCol]->getName())
			== std::isupper(board[currentRow - 1][currentCol + 1]->getName()))
		{
			return 6;
		}
	}
	return 0;
}

int Pawn::move(std::string& move)
{
	std::string targetSquare = std::to_string(move[2]) + std::to_string(move[3]);
	this->place = targetSquare;
	this->hasMoved = true;
	// Still have to check if player is check so we can return the correct code but for now we will just return 0
	
	return 0;
}
