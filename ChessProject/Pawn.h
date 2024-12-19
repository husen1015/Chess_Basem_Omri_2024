#pragma once
#include "Piece.h"


class Pawn : public Piece {

	Pawn();
	~Pawn();

	virtual char isTheMoveLegal(std::string& places) override;
	virtual void move(std::string& move) override;

};