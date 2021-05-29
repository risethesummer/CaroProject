#ifndef BOARD_H
#define BOARD_H
#include "Point.h"

class Board
{
	private:
		int size;
		Point anchor; //Top left anchor to print the board
		PointBoard** markedPoints; //Points to be marked by users

		/*
		bool CheckHorizontal(const Point&, const int&);
		bool CheckVertical(const Point&, const int&);
		bool CheckDiagonal(const Point&, const int&);
		*/

		//Receiving mark of the player (-1, 1)
		//And what dimenstion need to be active => (1, 0) => hor, (0, 1) => ver, (1, 1) => dia
		bool CheckState(const Point&, const int&, const Point&);
		Point CalculateIndexByPoint(const Point&);
	public:
		Board(int, Point);
		~Board();
		int GetSize();
		Point GetAnchor();
		void DrawBoard();
		int GetMarkAt(const Point&);
		bool InputMove(const Point&, const bool&); //Draw user's move and return the state of the board after moving
		void Clear(); //Clear previous data
};

#endif // !BOARD_H

