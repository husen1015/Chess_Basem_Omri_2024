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
	char getPlayer();
	// fields
	Piece* currentBoard[8][8];
private:
	char player;

};
