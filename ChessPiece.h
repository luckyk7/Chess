#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include "stdafx.h"
#include "VisibleGameObject.h"
#define WHITE true;
#define BLACK false;

class ChessPiece : public VisibleGameObject
{
private:
	bool team;
	//clicking on this rectangle allow user to control this piece
	sf::Rect<int> _clickBounds;

	//describes the pieces location on the board
	//int _x;
	//int _y;

public:
	ChessPiece();
	~ChessPiece();

	void updateBounds();

	//the board needs to point at piece in this spot
	//void setPosition(int x, int y);
	void setTeam();

	bool getTeam();
	//int getX();
	//int getY();

	
};



#endif
