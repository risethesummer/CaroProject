#ifndef POINT_H
#define POINT_H
#include <fstream>

class Point
{
	int x, y;
public:
	Point();
	Point(const int&, const int&);
	Point(const Point&);
	int GetX() const;
	int GetY() const;
	void SetX(const int&);
	void SetY(const int&);
	void Move(const int&, const int&);
	void MoveX(const int&);
	void MoveY(const int&);
	void MoveMultiply(const float&, const float&);
	void Move(const Point&);
	Point operator+(const Point&) const;
	Point operator-(const Point&) const;
	Point& operator=(const Point&);
	friend std::ifstream& operator>>(std::ifstream&, Point&);
};

#endif // !POINT_H

