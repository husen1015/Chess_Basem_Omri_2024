#pragma once
#include "Piece.h"
class Knight : public Piece {
public:
	Knight();
	Knight();
	virtual void move(std::string& places) override;
	virtual char isTheMoveLegal(std::string& places) override;
};