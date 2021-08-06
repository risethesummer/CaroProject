#include "SlotBoard.h"

SlotBoard::SlotBoard()
{
	mark = 0;
	xMark = nullptr;
	oMark = nullptr;
}

SlotBoard::SlotBoard(const vector<string>& content, const vector<string>& xShape,
	const vector<string>& oShape, const Point& anchor, const int& color) 
	: UIBound(content, anchor, color, Point(1, 1), YELLOW_YELLOW)
{
	mark = 0;
	Point temp(anchor.GetX() + 1, anchor.GetY());
	oMark = new UIComponent(oShape, temp, GREEN_GREEN);
	xMark = new UIComponent(xShape, temp, RED_RED);
}

int SlotBoard::GetMark() const
{
	return this->mark;
}


//Mark X is 1
//Mark O is 2
void SlotBoard::DrawMark() const
{
	if (mark == 1)
	{
		xMark->Show();
		return;
	}
	if (mark == 2)
		oMark->Show();
}


SlotBoard::~SlotBoard()
{
	delete xMark;
	delete oMark;
}

bool SlotBoard::SetMark(int mark)
{
	if (mark >= 0 && mark <= 2)
	{
		this->mark = mark;
		return true;
	}
	return false;
}