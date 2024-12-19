#pragma once
#include <string>
#include <iostream>

class Board {
public:
	// methods
	Board();
	~Board();
	void changeBoard(std::string move);
	// fields
	char currentBoard[8][8];

};
