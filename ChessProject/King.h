#pragma once
#include "Piece.h"


class King : public Piece {
public:
	King(std::string place, char color);
	~King();

	virtual int isTheMoveLegal(std::string& places, Piece* board[8][8]) override;
	virtual int move(std::string& move) override;

};