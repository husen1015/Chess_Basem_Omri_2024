#include "Rook.h"

Rook::Rook(std::string place, char color) : Piece(place, color)
{
}

Rook::~Rook()
{
}

int Rook::move(std::string& places)
{
	std::string targetSquare = std::to_string(places[2]) + std::to_string(place[3]);
	this->place = targetSquare;
	// Still have to check if player is check so we can return the correct code but for now we will just return 0
	return 0;
}

int Rook::isTheMoveLegal(std::string& places, Piece* board[8][8])
{
	std::string rooksPosition = std::to_string(places[0]) + std::to_string(place[1]); // Extract the current rooks position
	std::string targetSquare = std::to_string(places[2]) + std::to_string(place[3]);
	int currentCol = rooksPosition[0] - 'a'; // Convert from chess moves to array indexes
	int currentRow = std::abs(rooksPosition[1] - '8');
	int targetCol = targetSquare[0] - 'a';
	int targetRow = std::abs(targetSquare[1] - '8');
	int i = 0; // for loops


	if (rooksPosition[0] != targetSquare[0] && rooksPosition[1] != targetSquare[1] || checkIfPieceInTheWay(currentCol, targetCol, currentRow, targetRow, board))
	{
		return 6; // The rook can only move horizontly or vertically - 6 is the error code we return when a the user wants to do a move the piece cant do
	}

	// I still have to check for check but will do later
	return 0;
}

int Rook::checkIfPieceInTheWay(int currentCol, int targetCol, int currentRow, int targetRow, Piece* board[8][8])
{
	int i = 0;
	if (currentCol == targetCol) // Check if there is a piece in the way
	{
		if (currentRow > targetRow) // If the current row is bigger than the target row we decrese the i in the loop 
		{
			for (i = currentRow; i > targetRow; i--)
			{
				if (board[i][targetCol]->getName() != '#') // Check if there is a piece in the way
				{
					return 6; // If there is a piece in the way we return 6
				}
			}
		}
		else if (currentRow < targetRow)
		{
			for (i = currentRow; i < targetRow; i++)
			{
				if (board[i][targetCol]->getName() != '#') // Check if there is a piece in the way
				{
					return 6; // If there is a piece in the way we return 6
				}
			}

		}
	}
	else // If the coloum and the target coloum arnt equal then the rows are 
	{
		if (currentCol > targetCol) // If the current row is bigger than the target row we decrese the i in the loop 
		{
			for (i = currentCol; i > targetCol; i--)
			{
				if (board[targetRow][i]->getName() != '#') // Check if there is a piece in the way
				{
					return 6; // If there is a piece in the way we return 6
				}
			}
		}
		else if (currentCol < targetCol)
		{
			for (i = currentCol; i < targetCol; i++)
			{
				if (board[targetRow][i]->getName() != '#') // Check if there is a piece in the way
				{
					return 6; // If there is a piece in the way we return 6
				}
			}

		}
	}

}









