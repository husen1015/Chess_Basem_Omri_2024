#pragma once
#include "Piece.h"


class Queen : public Piece {

	Queen();
	~Queen();

	virtual char isTheMoveLegal(std::string& places) override;
	virtual void move(std::string& move) override;

};