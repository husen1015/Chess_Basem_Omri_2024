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
	std::string rooksPosition = std::to_string(places[0]) + std::to_string(place[1]); // Extract the current rooks position
	std::string targetSquare = std::to_string(places[2]) + std::to_string(place[3]);
	int currentCol = rooksPosition[0] - 'a'; // Convert from chess moves to array indexes
	int currentRow = std::abs(rooksPosition[1] - '8');
	int targetCol = targetSquare[0] - 'a';
	int targetRow = std::abs(targetSquare[1] - '8');
	if (std::abs(currentCol - targetCol) != std::abs(currentRow - targetRow) || checkIfPieceInTheWay(currentCol,targetCol,currentRow,targetRow,board) == 6)
	{
		return 6;
	}

	return 0;
}

int Bishop::checkIfPieceInTheWay(int currentCol, int targetCol, int currentRow, int targetRow, Piece* board[8][8])
{
	if (targetCol > currentCol)
	{
		if (targetRow < currentRow)
		{
			int i = std::abs(targetRow - currentRow) - 1;
			for (; i > 0; i--)
			{
				if (board[currentRow - i][currentCol + i]->getName() != '#')
				{
					return 6;
				}
			}
		}
		else
		{
			int i = std::abs(targetRow - currentRow) - 1;
			
			for (; i > 0; i--)
			{
				if (board[currentRow + i][currentCol + i]->getName() != '#')
				{
					return 6;
				}
			}
		}
	}
	else
	{
		if (targetRow < currentRow)
		{
			int i = std::abs(targetRow - currentRow) - 1;
			for (; i > 0; i--)
			{
				if (board[currentRow - i][currentCol - i]->getName() != '#')
				{
					return 6;
				}
			}
		}
		else
		{
			int i = std::abs(targetRow - currentRow) - 1;
			
			for (; i > 0; i--)
			{
				if (board[currentRow + i][currentCol - i]->getName() != '#')
				{
					return 6;
				}
			}
		}
	}
	return 0;
}
