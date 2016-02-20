#include "stdafx.h"
#include "game.h"
#include "ChessPiece.h"
#ifndef BOARD_H
#define BOARD_H
//global board that everything has access to 
class Board 
{
public:
	///returns true if [x][y] is an empty spot on the board
	static bool isEmpty(int x, int y);
	//static bool sameTeam();

private:
	//points to already created chesspieces
	static ChessPiece* _board[8][8];
};


#endif 