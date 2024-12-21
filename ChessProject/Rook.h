#pragma once
#include "Piece.h"
class Rook : public Piece {
public:
	Rook(std::string place, char color);
	~Rook();
	virtual void move(std::string& places) override;
	virtual char isTheMoveLegal(std::string& places) override;
};