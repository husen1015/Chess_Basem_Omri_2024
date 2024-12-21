#pragma once
#include "Piece.h"
class Bishop : public Piece {
public:
	Bishop(std::string place, char color);
	Bishop();
	virtual void move(std::string& places) override;
	virtual char isTheMoveLegal(std::string& places) override;
};