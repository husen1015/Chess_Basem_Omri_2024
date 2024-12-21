#pragma once
#include "Piece.h"


class Pawn : public Piece {
public:
	Pawn(std::string place, char color);
	~Pawn();

	virtual char isTheMoveLegal(std::string& places) override;
	virtual void move(std::string& move) override;

};