#ifndef UI_BOUND_H
#define UI_BOUND_H
#include "Color.h"
#include "Utility.h"
#include "UIComponent.h"


class UIBound : public UIComponent
{
private: 
	UIComponent* bound;
public:
	UIBound();
	UIBound(const vector<string>& content, const Point& anchor, const int& color);
	UIBound(const vector<string>& content, const Point& anchor, const int& color, const Point& boundOffset, const int& boundColor);
	void MakeBound(const Point& offset = { 1, 1 }, const int& color = RED_RED);
	void DrawBound();
	virtual void ClearBound(const int& replaceColor = DEFAULT);
	~UIBound();
};

#endif
