#include "Board.h"

Board::Board()
{
	char c = 'a';
	char num = '6';
	this->currentBoard[0][0] = new Rook("a8",'R');
	this->currentBoard[0][1] = new Knight("b8", 'N');
	this->currentBoard[0][2] = new Bishop("c8", 'B');
	this->currentBoard[0][3] = new King("d8", 'K');
	this->currentBoard[0][4] = new Queen("e8", 'Q');
	this->currentBoard[0][5] = new Bishop("f8", 'B');
	this->currentBoard[0][6] = new Knight("g8", 'N');
	this->currentBoard[0][7] = new Rook("h8", 'R');
	for (int i = 0,j = 1; i < 8; i++)
	{
		this->currentBoard[j][i] = new Pawn(char(int(c) + i) + "7",'P');
	}
	c = 'a';
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			this->currentBoard[i][j] = new Empty(std::to_string(char(int(c) + j)) + std::to_string(char(int(num) - i)), '#');
		}
	}
	c = 'a';
	for (int i = 0, j = 6; i < 8; i++)
	{
		this->currentBoard[j][i] = new Pawn(char(int(c) + i) + "2", 'p');
	}
	this->currentBoard[7][0] = new Rook("a1", 'r');
	this->currentBoard[7][1] = new Knight("b1", 'n');
	this->currentBoard[7][2] = new Bishop("c1", 'b');
	this->currentBoard[7][3] = new King("d1", 'k');
	this->currentBoard[7][4] = new Queen("e1", 'q');
	this->currentBoard[7][5] = new Bishop("f1", 'b');
	this->currentBoard[7][6] = new Knight("g1", 'n');
	this->currentBoard[7][7] = new Rook("h1", 'r');
	this->player = 'w';
}

Board::~Board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete this->currentBoard[i][j];
		}
	}
	delete[] this->currentBoard;
}

void Board::printBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << this->currentBoard[i][j]->getName() << ' ';
		}
		std::cout << "\n";
	}
}

int Board::changeBoard(std::string move)
{
	int moveCode = checkIfTheMoveIsLegalOnTheBoard(move);


	if (moveCode != 0 || moveCode != 1)
	{
		return moveCode; // If the move wasnt legal we return
	}

	std::string piecePostion = std::to_string(move[0]) + std::to_string(move[1]);
	std::string targetPostion = std::to_string(move[2]) + std::to_string(move[3]);
	int currentCol = piecePostion[0] - 'a';
	int currentRow = piecePostion[1] - '1';
	int targetCol = targetPostion[0] - 'a';
	int targetRow = targetPostion[1] - '1';

	moveCode = this->currentBoard[currentRow][currentCol]->move(move);

	delete this->currentBoard[targetRow][targetCol];

	this->currentBoard[targetRow][targetCol] = this->currentBoard[currentRow][currentCol];

	//delete this->currentBoard[currentRow][currentCol];

	
	this->currentBoard[currentRow][currentCol] = new Empty(piecePostion, '#');

	return moveCode;


}

char Board::getPlayer()
{
	return this->player;
}

int Board::checkIfTheMoveIsLegalOnTheBoard(std::string move)
{
	std::string piecePostion = std::to_string(move[0]) + std::to_string(move[1]);
	std::string targetPostion = std::to_string(move[2]) + std::to_string(move[3]);


	// We convert the moves in chess terms to indexes of the two dimensional array (a8 will be 0, 0)

	int currentCol = piecePostion[0] - 'a';
	int currentRow = piecePostion[1] - '1';
	int targetCol = targetPostion[0] - 'a';
	int targetRow = targetPostion[1] - '1';
	bool pieceKill = false; // Flag that symbols if we intend to kill a piece in the move usefull for error code 3
	if (std::isalpha(this->currentBoard[targetRow][targetCol]->getName()))
	{
		pieceKill = true; // If there is a piece in the targeted square then the user intends to kill a piece
	}
	
	if (currentRow > 7 || currentRow < 0 || currentCol > 7 || currentCol < 0 || targetCol < 0||
		targetCol > 7 || targetRow < 0 || targetCol > 7)
	{
		return 5; // 5 is the error code we return if the indexes are invalid (out of the board range)
	}

	if (this->currentBoard[currentRow][currentCol]->getName() == '#' || std::isupper(this->currentBoard[currentRow][currentCol]->getName()) && this->player == 'b' || std::islower(this->currentBoard[currentRow][currentCol]->getName()) && this->player == 'w')
	{
		return 2; // 2 Is the error code we return if there isnt currently a piece of the current player on the specified position
	}

	if (targetCol == currentCol && targetRow  == currentRow)
	{
		return 7; // 7 is the error code we return when the target position is the same as the current position
	}
	if (pieceKill && std::isupper(this->currentBoard[currentRow][currentCol]->getName() == std::isupper(this->currentBoard[targetRow][targetCol]->getName()))) // Check if we want to kill a piece the same color as us
	{
		return 3; // 3 is the error code we return if the player tries to kill there own piece 
	}

	return this->currentBoard[currentRow][currentCol]->isTheMoveLegal(move, this->currentBoard);
}
