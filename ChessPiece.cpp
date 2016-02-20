#include "ChessPiece.h"

ChessPiece::ChessPiece()
{
}

ChessPiece::~ChessPiece()
{
}

//keep the rect a 75*75 area center on vis Gam obj cords
void ChessPiece::updateBounds()
{
	
}
/*
void ChessPiece::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}


int ChessPiece::getX()
{
	return _x;
}

int ChessPiece::getY()
{
	return _y;
}
*/

bool ChessPiece::getTeam()
{
	return team;
}