#pragma once
#include <string>
#include <iostream>
#include "Piece.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Empty.h"
#include "King.h"
class Board {
public:
	// methods
	Board();
	~Board();
	void printBoard();
	int changeBoard(std::string move);
	bool isCheck(char player);
	bool isCheckMate(char player);
	std::string boardInMessage();
	// fields
	Piece* currentBoard[8][8];
	char getPlayer();
private:
	char player;
	// helper function
	// Function checks if the move is legal in board terms
	int checkIfTheMoveIsLegalOnTheBoard(std::string move); // the name is too long might change later but this will do for now
};
