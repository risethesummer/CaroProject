#ifndef POINTBOARD_H
#define POINTBOARD_H
#include "Point.h"
#include "Color.h"
#include "UIBound.h"

class SlotBoard : public UIBound
{
private:
	int mark;
	//Draw X or O
	UIComponent* oMark; 
	UIComponent* xMark; 
public:
	SlotBoard();
	SlotBoard(const vector<string>& content, const vector<string>& xShape, const vector<string>& oShape,
		const Point& anchor, const int& color);
	bool SetMark(int);
	int GetMark() const;
	void DrawMark() const;
	virtual ~SlotBoard();
};


#endif // !POINTBOARD_H

