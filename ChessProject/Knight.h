#pragma once
#include "Piece.h"
class Knight : public Piece {
public:
	Knight(std::string place, char color);
	~Knight();
	virtual int move(std::string& places) override;
	virtual int isTheMoveLegal(std::string& places, Piece* board[8][8]) override;
};