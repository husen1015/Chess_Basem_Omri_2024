#pragma once
#include "Piece.h"
class Bishop : public Piece {
public:
	Bishop();
	Bishop();
	virtual void move(std::string& places) override;
	virtual char isTheMoveLegal(std::string& places) override;
};