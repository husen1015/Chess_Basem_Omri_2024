#pragma once
#include <string>
#include <iostream>
#include <math.h>
#include <cctype>
class Piece {
public:
	Piece(std::string place, char name); // Changed from char color to char name since the color is accutally the name
	~Piece();
	char getColor() const;
	char getName() const; // Changed from get color to get name so the code can be more readble
	virtual int move(std::string& places) = 0; // changed from void to int so we can return the code
	virtual int isTheMoveLegal(std::string& places, Piece* board[8][8]) = 0;
	std::string getPlace() const;
protected:
	bool isAlive;
	char typeAndColor;
	std::string place;
};