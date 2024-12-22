#pragma once
#include "Bishop.h"
#include "Rook.h"

class Queen : public Bishop , public Rook {
public:
	Queen(std::string place,char color);
	~Queen();

	virtual int isTheMoveLegal(std::string& places, Piece* board[8][8]) override;
	virtual int move(std::string& move) override; 

};