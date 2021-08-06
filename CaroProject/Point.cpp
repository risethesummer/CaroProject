#include "Point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(const int& x, const int& y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& p)
{
	x = p.GetX();
	y = p.GetY();
}

int Point::GetX() const
{
	return x;
}

int Point::GetY() const
{
	return y;
}

void Point::SetX(const int& x)
{
	this->x = x;
}

void Point::SetY(const int& y)
{
	this->y = y;
}

void Point::Move(const int& dX, const int& dY)
{
	this->x += dX;
	this->y += dY;
}

void Point::MoveX(const int& dX)
{
	this->x += dX;
}

void Point::MoveY(const int& dY)
{
	this->y += dY;
}

void Point::MoveMultiply(const float& dX, const float& dY)
{
	this->x *= dX;
	this->y *= dY;
}

void Point::Move(const Point& d)
{
	Move(d.GetX(), d.GetY());
}

Point Point::operator+(const Point& a) const	
{
	Point result = Point{ x + a.GetX(), y + a.GetY() };
	return result;
}

Point Point::operator-(const Point& a) const
{
	Point result = Point{ x - a.GetX(), y - a.GetY() };
	return result;
}

Point& Point::operator=(const Point& a)
{
	SetX(a.GetX());
	SetY(a.GetY());
	return *this;
}
