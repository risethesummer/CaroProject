#include "Point.h"

Point operator-(Point a, Point b)
{
	return { a.x - b.x, a.y - b.y };
}

Point operator+(Point a, Point b)
{
	return { a.x + b.x, a.y + b.y };
}

PointBoard::PointBoard()
{
	this->coor = { 0, 0 };
	this->mark = 0; //Not marked
}

PointBoard::PointBoard(int x, int y)
{
	this->coor = { x, y };
	this->mark = 0; //Not marked
}

Point PointBoard::GetCoordinate()
{
	return this->coor;
}

void PointBoard::SetCoordinate(Point p)
{
	this->coor = p;
}


int PointBoard::GetMark()
{
	return this->mark;
}

bool PointBoard::SetMark(int mark)
{
	if (mark >= -1 && mark <= 1)
	{
		this->mark = mark;
		return true;
	}
	return false;
}