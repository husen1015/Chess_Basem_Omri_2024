#pragma once
#include "Piece.h"


class Pawn : public Piece {
private:
	bool hasMoved;
public:
	Pawn(std::string place, char color);
	~Pawn();

	virtual int isTheMoveLegal(std::string& places, Piece* board[8][8]) override;
	virtual int move(std::string& move) override;

};