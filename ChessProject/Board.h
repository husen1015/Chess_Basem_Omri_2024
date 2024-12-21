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
	void changeBoard(std::string move);
	// fields
	Piece* currentBoard[8][8];
	char getPlayer();
private:
	char player;
};
