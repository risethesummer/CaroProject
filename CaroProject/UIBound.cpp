#include "UIBound.h"

UIBound::UIBound()
{
	bound = nullptr;
}

UIBound::UIBound(const vector<string>& content, const Point& anchor, const int& color)
	: UIComponent(content, anchor, color)
{
	Point temp(1, 1);
	bound = new UIComponent(Utility::CreateRectangleContent(content, temp), anchor - temp, RED_RED);
}

UIBound::UIBound(const vector<string>& content, const Point& anchor, const int& color, const Point& boundOffset, const int& boundColor)
	: UIComponent(content, anchor, color)
{
	MakeBound(boundOffset, boundColor);
}

void UIBound::MakeBound(const Point& offset, const int& color)
{
	bound = new UIComponent(Utility::CreateRectangleContent(content, offset), anchor - offset, color);
}

void UIBound::DrawBound()
{
	if (!bound)
		MakeBound();
	bound->Show();
}

void UIBound::ClearBound(const int& replaceColor)
{
	if (bound)
		bound->Hide(replaceColor);
}


UIBound::~UIBound()
{
	if (bound)
		delete bound;
}
