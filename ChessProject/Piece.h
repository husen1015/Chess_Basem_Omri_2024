#pragma once
#include <string>
#include <iostream>
class Piece {
public:
	Piece(std::string place, char color);
	~Piece();
	std::string getColor();
	virtual void move(std::string& places)=0;
	virtual char isTheMoveLegal(std::string& places)=0;
private:
	bool isAlive;
	char typeAndColor;
	std::string place;
};