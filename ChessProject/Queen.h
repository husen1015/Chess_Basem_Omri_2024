#pragma once
#include "Piece.h"


class Queen : public Piece {
public:
	Queen(std::string place,char color);
	~Queen();

	virtual int isTheMoveLegal(std::string& places, Piece* board[8][8]) override;
	virtual int move(std::string& move) override; 

};