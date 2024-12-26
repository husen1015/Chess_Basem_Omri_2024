#pragma once
#include "Bishop.h"
#include "Rook.h"

class Queen : public Piece {
public:
	Queen(std::string place,char color);
	~Queen();

	virtual int isTheMoveLegal(std::string& places, Piece* board[8][8]) override;
	virtual int move(std::string& move) override; 
	int checkIfPieceInTheWayB(int currentCol, int targetCol, int currentRow, int targetRow, Piece* board[8][8]);
	int checkIfPieceInTheWayR(int currentCol, int targetCol, int currentRow, int targetRow, Piece* board[8][8]);

};