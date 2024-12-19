#pragma once
#include "Piece.h"
class Empty : public Piece {
public:
	Empty();
	Empty();
	virtual void move(std::string& places) override;
	virtual char isTheMoveLegal(std::string& places) override;
};