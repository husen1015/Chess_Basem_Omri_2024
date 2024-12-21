#pragma once
#include "Piece.h"
class Knight : public Piece {
public:
	Knight(std::string place, char color);
	Knight();
	virtual void move(std::string& places) override;
	virtual char isTheMoveLegal(std::string& places) override;
};