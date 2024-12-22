#pragma once
#include "Piece.h"
class Bishop : public Piece {
public:
	Bishop(std::string place, char color);
	~Bishop();
	virtual int move(std::string& places) override;
	virtual int isTheMoveLegal(std::string& places, Piece* board[8][8]) override;
private:
	int checkIfPieceInTheWay(int currentCol, int targetCol, int currentRow, int targetRow, Piece* board[8][8]);
};