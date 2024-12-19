#pragma once
#include "Piece.h"


class King : public Piece {

	King();
	~King();

	virtual char isTheMoveLegal(std::string& places) override;
	virtual void move(std::string& move) override;

};