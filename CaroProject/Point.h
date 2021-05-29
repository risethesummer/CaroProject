#ifndef POINT_H
#define POINT_H

struct Point
{
	int x, y;
};
Point operator-(Point, Point);
Point operator+(Point, Point);

class PointBoard
{
	private:
		Point coor;
		int mark;
	public:
		PointBoard();
		PointBoard(int, int);
		bool SetMark(int);
		int GetMark();
		Point GetCoordinate();
		void SetCoordinate(Point);
};

#endif // !POINT_H

