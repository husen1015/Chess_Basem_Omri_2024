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
	for (int i = 3; i < 7; i++)
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
			std::cout << this->currentBoard[i][j]->getColor() << ' ';
		}
		std::cout << "\n";
	}
}

void Board::changeBoard(std::string move)
{

}

char Board::getPlayer()
{
	return this->player;
}
