#pragma once
#include "Piece.h"


class Queen : public Piece {
public:
	Queen(std::string place,char color);
	~Queen();

	virtual char isTheMoveLegal(std::string& places) override;
	virtual void move(std::string& move) override;

};