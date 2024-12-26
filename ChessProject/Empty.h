#pragma once
#include "Piece.h"
class Empty : public Piece {
public:
	Empty(std::string place, char color);
	~Empty();
	virtual int move(std::string& places) override;
	virtual int isTheMoveLegal(std::string& places, Piece* board[8][8]) override;
};