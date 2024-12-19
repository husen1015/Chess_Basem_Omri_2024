#pragma once
#include "Piece.h"
class Rook : public Piece {
public:
	Rook();
	~Rook();
	virtual void move(std::string& places) override;
	virtual char isTheMoveLegal(std::string& places) override;
};