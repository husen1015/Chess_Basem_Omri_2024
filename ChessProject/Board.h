#pragma once
#include <string>
#include <iostream>
#include "Piece.h"

class Board {
public:
	// methods
	Board();
	~Board();
	void changeBoard(std::string move);
	// fields
	Piece* currentBoard[8][8];
};
