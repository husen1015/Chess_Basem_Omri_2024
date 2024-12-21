#pragma once
#include "Piece.h"


class King : public Piece {
public:
	King(std::string place, char color);
	~King();

	virtual char isTheMoveLegal(std::string& places) override;
	virtual void move(std::string& move) override;

};