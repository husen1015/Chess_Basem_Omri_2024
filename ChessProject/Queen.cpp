#include "Queen.h"

Queen::Queen(std::string place, char color) : Piece(place,color)
{

}

Queen::~Queen()
{
}

int Queen::isTheMoveLegal(std::string& places, Piece* board[8][8])
{
	std::string rooksPosition = std::to_string(places[0]) + std::to_string(place[1]); // Extract the current rooks position
	std::string targetSquare = std::to_string(places[2]) + std::to_string(place[3]);
	int currentCol = rooksPosition[0] - 'a'; // Convert from chess moves to array indexes
	int currentRow = std::abs(rooksPosition[1] - '8');
	int targetCol = targetSquare[0] - 'a';
	int targetRow = std::abs(targetSquare[1] - '8');
	if (std::abs(currentCol - targetCol) != std::abs(currentRow - targetRow) || checkIfPieceInTheWayB(currentCol, targetCol, currentRow, targetRow, board) == 6)
	{
		return 6;
	}
	if (rooksPosition[0] != targetSquare[0] && rooksPosition[1] != targetSquare[1] || checkIfPieceInTheWayR(currentCol, targetCol, currentRow, targetRow, board))
	{
		return 6;
	}
	return 0;
}

int Queen::move(std::string& move)
{
	std::string targetSquare = std::to_string(move[2]) + std::to_string(move[3]);
	this->place = targetSquare;
	return 0;
}
int Queen::checkIfPieceInTheWayB(int currentCol, int targetCol, int currentRow, int targetRow, Piece* board[8][8])
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
int Queen::checkIfPieceInTheWayR(int currentCol, int targetCol, int currentRow, int targetRow, Piece* board[8][8])
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
