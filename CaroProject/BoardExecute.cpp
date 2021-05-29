#include "Board.h"
#include "Screen.h"
#define TIMETOWIN 3

Board::Board(int size, Point anchor)
{
	this->size = size;
	this->anchor = anchor;

	this->markedPoints = new PointBoard * [size];
	for (int i = 0; i < size; i++)
	{
		markedPoints[i] = new PointBoard[size];

		//Assign fixed coordinates for markedPoints
		for (int j = 0; j < size; j++)
		{
			//Default value
			markedPoints[i][j].SetCoordinate({ 4 * j + anchor.x + 2, 2 * i + anchor.y + 1 });
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < size; i++)
		delete [] this->markedPoints[i];
	delete this->markedPoints;
}

int Board::GetSize()
{
	return size;
}

Point Board::GetAnchor()
{
	return this->anchor;
}

void Board::DrawBoard()
{
	if (markedPoints) // firstly call constructor 
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++) {
				Screen::Draw(this->markedPoints[i][j].GetCoordinate(), ".");
			}
		}
		Screen::Jump(this->markedPoints[0][0].GetCoordinate());
	}
}

bool Board::InputMove(const Point& move, const bool& who)
{
	Point index = CalculateIndexByPoint(move);
	int tempMark = 0;
	//If user 1
	if (who)
	{
		tempMark = 1;
		markedPoints[index.x][index.y].SetMark(1);
		Screen::Draw(move, "X");
	}
	else //User 2
	{
		tempMark = -1;
		markedPoints[index.x][index.y].SetMark(-1);
		Screen::Draw(move, "O");
	}

	//Need at least 1 of 3 dimension fitting the condition
	return CheckState(index, tempMark, Point{ 1, 0 })
		|| CheckState(index, tempMark, Point{ 0, 1 })
		|| CheckState(index, tempMark, Point{ 1, 1 });
}

Point Board::CalculateIndexByPoint(const Point& p)
{
	//Caculate the index depending on the coordinate
	Point refPosition = p - anchor - Point{ 2 , 1 }; //-offset we drew
	refPosition.x /= 4;
	refPosition.y /= 2;

	return refPosition;
}

void Board::Clear()
{
	if (this->markedPoints)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				//Default value
				markedPoints[i][j].SetCoordinate({ 4 * j + anchor.x + 2, 2 * i + anchor.y + 1 });
				markedPoints[i][j].SetMark(0);
			}
		}
	}
}

int Board::GetMarkAt(const Point& index)
{
	if (index.x >= 0 && index.x < size && index.y >= 0 && index.y < size)
		return markedPoints[index.x][index.y].GetMark();
	return 0; //Error -> means not marked
}

bool Board::CheckState(const Point& point, const int& mark, const Point& dimenson)
{
	//2 sides of the point are empty
	if (!(GetMarkAt(point + dimenson) == mark)
		&& !(GetMarkAt(point - dimenson) == mark))
		return false;

	int count = 0;
	//From bottom/left (p - timetowin) => top/right (p + timetowin)
	Point offset = dimenson;
	for (int i = -TIMETOWIN; i <= TIMETOWIN; i++)
	{
		//Current offset from the point
		offset = { dimenson.x * i, dimenson.y * i };
		if (GetMarkAt(point + offset) == mark)
		{
			count++;
			if (count >= TIMETOWIN) //TIMETOWIN continous marks 
				return true;
		}
		else
			count = 0; //Not continous => reset to 0
	}

	return false; //Not exist a vertical meeting the condition
}